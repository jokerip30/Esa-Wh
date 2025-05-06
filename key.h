#pragma once
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <dbt.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <windowsx.h>

#pragma comment (lib,"dinput8.lib")
#pragma comment (lib,"dxguid.lib")

/////////////////////////////////////////////////////////////////////////////////
LPDIRECTINPUT8 Input;
void InitializeDirectInput();
void UpdateDirectInput();
void DirectInputLoop();
/////////////////////////////////////////////////////////////////////////////////
LPDIRECTINPUTDEVICE8 Keyboard;
void InitializeKeyboard();
void UpdateKeyboard();
char* getKeyboardState();
bool IsKeyboardKeyDownOnce(int Index);

char KeyboardState[256];
bool KeyPressed[256] = { 0 };
/////////////////////////////////////////////////////////////////////////////////
LPDIRECTINPUTDEVICE8 Mouse;
void InitializeMouse();
void UpdateMouse();

typedef struct {
	int x;          //x-location of mouse
	int y;          //y-location of mouse
	bool button[2];  //is button 1 held down?
} MOUSE;

MOUSE mouse;
//char MouseState[256];
DIMOUSESTATE2 MouseState;
bool MousePressed[2] = { 0 };
HANDLE MouseEvent;
#define DIM_LBUTTON 0
#define DIM_RBUTTON 1
#define DIM_MBUTTON 2
/////////////////////////////////////////////////////////////////////////////////

void InitializeDirectInput()
{
	DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&Input, NULL);
}
void UpdateDirectInput()
{
	if (Keyboard == NULL || Mouse == NULL)
	{
		InitializeKeyboard();
		InitializeMouse();
	}
	else
	{
		UpdateKeyboard();
		UpdateMouse();
	}
}
void DirectInputLoop()
{
	if (Input == NULL)
		InitializeDirectInput();
	else
		UpdateDirectInput();
}
/////////////////////////////////////////////////////////////////////////////////
void InitializeKeyboard()
{
	Input->CreateDevice(GUID_SysKeyboard, &Keyboard, NULL);
	Keyboard->SetDataFormat(&c_dfDIKeyboard);
	Keyboard->SetCooperativeLevel(GetForegroundWindow(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	Keyboard->Acquire();
}
void InitializeMouse()
{
	Input->CreateDevice(GUID_SysMouse, &Mouse, NULL);
	Mouse->SetDataFormat(&c_dfDIMouse2);
	Mouse->SetCooperativeLevel(GetForegroundWindow(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	Mouse->Acquire();
}

void UpdateKeyboard()
{
	HRESULT res = Keyboard->GetDeviceState(sizeof(KeyboardState), (LPVOID)&KeyboardState);
	if FAILED(res)
	{
		Keyboard->Release();
		Keyboard = NULL;
		return;
	}
}
void UpdateMouse()
{
	HRESULT res = Mouse->GetDeviceState(sizeof(MouseState), (LPVOID)&MouseState);
	if FAILED(res)
	{
		Mouse->Release();
		Mouse = NULL;
		return;
	}
}

bool GetKeyboardPressState(int nIndex)
{
	return (KeyboardState[nIndex] && 0x80);
}

bool GetMousePressState(int nIndex)
{
	return (MouseState.rgbButtons[nIndex] && 0x80);
}

bool IsKeyboardKeyDownOnce(int Index) {
	if (GetKeyboardPressState(Index)) {
		if (KeyPressed[Index] == false) {
			KeyPressed[Index] = true;
			return true;
		}
		else return false;
	}
	else KeyPressed[Index] = false;
	return false;
}

bool IsMouseKeyDownOnce(int Index) {
	if (GetMousePressState(Index)) {
		if (KeyPressed[Index] == false) {
			KeyPressed[Index] = true;
			return true;
		}
		else return false;
	}
	else KeyPressed[Index] = false;
	return false;
}

static struct key_s
{
	bool bPressed;
	DWORD dwStartTime;
}
kPressingKey[256];
BOOL IsKeyPressed(int Key, DWORD dwTimeOut)
{
	if (HIWORD(GetKeyState(Key)))
	{
		if (!kPressingKey[Key].bPressed || (kPressingKey[Key].dwStartTime && (kPressingKey[Key].dwStartTime + dwTimeOut) <= GetTickCount()))
		{
			kPressingKey[Key].bPressed = TRUE;
			if (dwTimeOut > NULL)
				kPressingKey[Key].dwStartTime = GetTickCount();
			return TRUE;
		}
	}
	else
		kPressingKey[Key].bPressed = FALSE;
	return FALSE;
}

typedef SHORT(WINAPI* CGetAsyncKeyState)(_In_ int);
LPVOID pKey = VirtualAlloc(NULL, 0x32000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
CGetAsyncKeyState  pGetAsyncKeyState = static_cast<CGetAsyncKeyState>(pKey);

BOOL D3DKeyboard(int Key, DWORD dwTimeOut)
{
	if (HIWORD(pGetAsyncKeyState(Key)))
	{
		if (!kPressingKey[Key].bPressed || (kPressingKey[Key].dwStartTime && (kPressingKey[Key].dwStartTime + dwTimeOut) <= GetTickCount()))
		{
			kPressingKey[Key].bPressed = TRUE;
			if (dwTimeOut > NULL)
				kPressingKey[Key].dwStartTime = GetTickCount();
			return TRUE;
		}
	}
	else
		kPressingKey[Key].bPressed = FALSE;
	return FALSE;
}