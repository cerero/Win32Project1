#include "stdafx.h"
#include "demo8_12.h"

// demo globals
static BOB generator,  // the generator BOB
alien,      // a little alien ship BOB
beacon;     // a beacon BOB

static int world_x = 0,   // current position of viewing window
world_y = 0;

static SPARSE_OBJ world[NUM_OBJECTS_UNIVERSE]; // our world consists of 256 objects randomly placed in the universe
// that is 10x10

static char buffer[80];                // used to print text

int demo8_12::init(void *param, int num_parms)
{
	int index;         // looping var
	char filename[80]; // used to build up files names

	// initialize directdraw
	DDraw_Init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);

	// load in the generator bob image
	Load_Bitmap_File(&bitmap8bit, "chap8\\GENS4.BMP");

	// set the palette to the palette of the generators
	Set_Palette(bitmap8bit.palette);


	// create the generator bob
	if (!Create_BOB(&generator, 0, 0, 72, 84, 4,
		BOB_ATTR_VISIBLE | BOB_ATTR_MULTI_FRAME, DDSCAPS_SYSTEMMEMORY))
		return(0);

	// load each bitmap into the generator BOB object
	for (index = 0; index < 4; index++)
		Load_Frame_BOB(&generator, &bitmap8bit, index, index % 4, index / 4, BITMAP_EXTRACT_MODE_CELL);

	// set up stating state of bob
	Set_Animation_BOB(&generator, 0);
	Set_Anim_Speed_BOB(&generator, 4);

	// unload the map bitmap
	Unload_Bitmap_File(&bitmap8bit);


	// load in the alien bob image
	Load_Bitmap_File(&bitmap8bit, "chap8\\ALIENS0.BMP");

	// create the alien bob
	if (!Create_BOB(&alien, 0, 0, 56, 30, 8,
		BOB_ATTR_VISIBLE | BOB_ATTR_MULTI_FRAME, DDSCAPS_SYSTEMMEMORY))
		return(0);

	// load each bitmap into the alien BOB object
	for (index = 0; index < 8; index++)
		Load_Frame_BOB(&alien, &bitmap8bit, index, index % 5, index / 5, BITMAP_EXTRACT_MODE_CELL);

	// set up stating state of bob
	Set_Animation_BOB(&alien, 0);
	Set_Anim_Speed_BOB(&alien, 4);

	// unload the bitmap
	Unload_Bitmap_File(&bitmap8bit);



	// load in the beacon bob image
	Load_Bitmap_File(&bitmap8bit, "chap8\\PIPE0.BMP");

	// create the alien bob
	if (!Create_BOB(&beacon, 0, 0, 42, 36, 8,
		BOB_ATTR_VISIBLE | BOB_ATTR_MULTI_FRAME, DDSCAPS_SYSTEMMEMORY))
		return(0);

	// load each bitmap into the beacon BOB object
	for (index = 0; index < 8; index++)
		Load_Frame_BOB(&beacon, &bitmap8bit, index, index % 6, index / 6, BITMAP_EXTRACT_MODE_CELL);

	// set up stating state of bob
	Set_Animation_BOB(&beacon, 0);
	Set_Anim_Speed_BOB(&beacon, 4);

	// unload the bitmap
	Unload_Bitmap_File(&bitmap8bit);


	// set clipping rectangle to screen extents so mouse cursor
	// doens't mess up at edges
	RECT screen_rect = { 0, 0, screen_width, screen_height };
	lpddclipper = DDraw_Attach_Clipper(lpddsback, 1, &screen_rect);

	// hide the mouse
	ShowCursor(FALSE);

	// now generate the sparse universe
	for (index = 0; index < NUM_OBJECTS_UNIVERSE; index++)
	{
		// set random position
		world[index].x = rand() % MAX_UNIVERSE_X;
		world[index].y = rand() % MAX_UNIVERSE_Y;

		// set type
		world[index].type = rand() % 3; // 0, 1, 2 generator, alien, beacon

	} // end for index
	return 1;
}

int demo8_12::shutdown(void *param, int num_parms)
{
	// kill objects
	Destroy_BOB(&alien);
	Destroy_BOB(&generator);
	Destroy_BOB(&beacon);

	// shutdonw directdraw
	DDraw_Shutdown();
	return 1;
}

int demo8_12::main(void *param, int num_parms)
{
	int index, index_x, index_y;  // looping vars
	int screen_x, screen_y;       // screen coords
	int width, height, type;      // used to extract bob info
	int x0, y0, x1, y1; // used to compute the upper left and lower right corners of each object
	int visible = 0; // number of visible objects

	BOB_PTR object_ptr = NULL; // the object that is going to be rendered

	// check of user is trying to exit
	if (KEY_DOWN(VK_ESCAPE) || KEY_DOWN(VK_SPACE))
		PostMessage(main_window_handle, WM_DESTROY, 0, 0);

	// start the timing clock
	Start_Clock();

	// clear the drawing surface
	DDraw_Fill_Surface(lpddsback, 0);

	// check for movement (scrolling)
	if (KEY_DOWN(VK_RIGHT))
	{
		if ((world_x += 8) >= 5760)
			world_x = 5760 - 1;

	} // end if
	else
	if (KEY_DOWN(VK_LEFT))
	{
		if ((world_x -= 8) < 0)
			world_x = 0;

	} // end if

	if (KEY_DOWN(VK_UP))
	{
		if ((world_y -= 8) < 0)
			world_y = 0;

	} // end if
	else
	if (KEY_DOWN(VK_DOWN))
	{
		if ((world_y += 8) >= 4320)
			world_y = 4320 - 1;

	} // end if

	// based on current world position which defines the viewport, i.e,
	// world_x, world_y to world_x+640-1, world_y+480-1, scan the object list
	// determine any object in that region translate it to screen coords and render it


	for (index = 0, visible = 0; index < NUM_OBJECTS_UNIVERSE; index++)
	{
		// get the object position
		x0 = world[index].x;
		y0 = world[index].y;

		// now translate to screen coords, could have done above, but clearer
		x0 = x0 - world_x;
		y0 = y0 - world_y;

		// get type, so we can compute size
		type = world[index].type;

		// compute size
		switch (type)
		{
		case GENERATOR_OBJ:
		{
							  // get size of this object
							  width = generator.width;
							  height = generator.height;

							  // point to it to render it easier without another switch
							  object_ptr = &generator;
		} break;

		case BEACON_OBJ:
		{
						   // get size of this object
						   width = beacon.width;
						   height = beacon.height;

						   // point to it to render it easier without another switch
						   object_ptr = &beacon;
		} break;

		case ALIEN_OBJ:
		{
						  // get size of this object
						  width = alien.width;
						  height = alien.height;

						  // point to it to render it easier without another switch
						  object_ptr = &alien;

		} break;

		default: break;

		} // end switch

		// compute extents based on width,height
		x1 = x0 + width - 1;
		y1 = y0 + height - 1;

		// do clip trivial clip
		if ((x0 >= SCREEN_WIDTH) || (x1 < 0) || (y0 >= SCREEN_HEIGHT) || (y1 < 0))
			continue; // don't need to render this one
		else
		{
			// render this object
			object_ptr->x = x0;
			object_ptr->y = y0;

			Draw_BOB(object_ptr, lpddsback);

			visible++;

		} // end else

	} // end for index

	// animate all the bobs
	Animate_BOB(&generator);
	Animate_BOB(&beacon);
	Animate_BOB(&alien);

	// draw some info
	Draw_Text_GDI("USE ARROW KEYS TO MOVE, <ESC> to Exit.", 8, 8, RGB(0, 255, 0), lpddsback);

	sprintf_s(buffer, "World Position = [%d, %d]  Objects Visible = %d, Objects Clipped = %d   ", world_x, world_y, visible, 256 - visible);
	Draw_Text_GDI(buffer, 8, screen_height - 32, RGB(0, 255, 0), lpddsback);

	// flip the surfaces
	DDraw_Flip();

	// sync to 30 fps
	Wait_Clock(30);
	return 1;
}