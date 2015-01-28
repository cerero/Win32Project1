// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#ifndef STDAFX_H
#define STDAFX_H

#include "targetver.h"


#define WINDOW_CLASS_NAME "T3D_CONSOLE" // defines for windows 


// MACROS /////////////////////////////////////////////////
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件: 
#include <windows.h>
#include <windowsx.h> 

// C 运行时头文件
#include <stdlib.h>
// GLOBALS ////////////////////////////////////////////////
//HWND      main_window_handle = NULL; // globally track main window
//HINSTANCE hinstance_app = NULL; // globally track hinstance

#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <mmsystem.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h> 
#include <math.h>
#include <io.h>
#include <fcntl.h>

#include <iostream>
#include "t3dlib1.h"
// TODO:  在此处引用程序需要的其他头文件

#endif

