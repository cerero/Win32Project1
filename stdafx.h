// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#ifndef STDAFX_H
#define STDAFX_H

#include "targetver.h"


#define WINDOW_CLASS_NAME "T3D_CONSOLE" // defines for windows 


// MACROS /////////////////////////////////////////////////
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>
#include <windowsx.h> 

// C ����ʱͷ�ļ�
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
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

#endif

