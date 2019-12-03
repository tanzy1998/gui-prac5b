#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <conio.h>
#include <string>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "Practical 5"
float rotatedeg = 0.0, z = 0, speed = 1.0;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CHAR:
		switch (wParam)
		{
			
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case VK_UP:
			z += speed;
			break;
		case VK_DOWN:
			z -= speed;
			break;
		}
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void topping() {
	glPushMatrix();
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	glTranslatef(-0.025, 0.27, 0.154);
	glColor3f(1, 1, 0);
	glRotatef(110, 1, 1, 0);
	gluCylinder(cylinder, 0.01, 0.01, 0.01, 15, 15);
	gluDeleteQuadric(cylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder = gluNewQuadric();
	glTranslatef(0.0, 0.35, 0.11);
	glColor3ub(255, 128, 0);
	glRotatef(110, 1, 1, 0);
	gluCylinder(cylinder, 0.01, 0.01, 0.01, 15, 15);
	gluDeleteQuadric(cylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder = gluNewQuadric();
	glTranslatef(-0.05, 0.35, 0.1);
	glColor3ub(255, 255, 51);
	glRotatef(110, 1, 1, 0);
	gluCylinder(cylinder, 0.01, 0.01, 0.01, 15, 15);
	gluDeleteQuadric(cylinder);
	glPopMatrix();
}

void icecream() {
	glPushMatrix();
	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();
	glColor3ub(51, 25, 0);
	glTranslatef(0, 0.23, 0);
	//glRotatef(270, 1, 0, 0);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, 0.16, 30, 30);
	gluDeleteQuadric(sphere);
	glPopMatrix();

	glPushMatrix();
	sphere = gluNewQuadric();
	glColor3f(1, 1, 1);
	glTranslatef(0, 0.05, 0);
	//glRotatef(270, 1, 0, 0);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, 0.175, 30, 30);
	gluDeleteQuadric(sphere);
	glPopMatrix();
}

void cone() {
	glPushMatrix();
	GLUquadricObj* cyllinder = NULL;
	cyllinder = gluNewQuadric();
	glColor3ub(153, 76, 0);
	glTranslatef(0, -0.5, 0);
	glRotatef(270, 1, 0, 0);
	gluQuadricDrawStyle(cyllinder, GLU_FILL);
	gluCylinder(cyllinder, 0.0, 0.18, 0.5, 20, 30);
	gluDeleteQuadric(cyllinder);
	glPopMatrix();

	glPushMatrix();
	cyllinder = gluNewQuadric();
	glColor3ub(0, 0, 0);
	glTranslatef(0, -0.5, 0);
	glRotatef(270, 1, 0, 0);
	gluQuadricDrawStyle(cyllinder, GLU_LINE);
	gluCylinder(cyllinder, 0.0, 0.18, 0.5, 20, 30);
	gluDeleteQuadric(cyllinder);
	glPopMatrix();
}

void myRoll()
{
	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	glPushMatrix();
	glColor3ub(87, 48, 0);
	glTranslatef(0.05, 0.25, 0.05);
	glRotatef(-90, 1, 0, 1);
	//gluQuadricDrawStyle(var, GLU_LINE);
	gluCylinder(var, 0.03f, 0.03f, 0.3f, 32, 32);
	glPopMatrix();
}

void display()
{
	rotatedeg += 0.05;
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	//glRotatef(rotatedeg, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, z);
	cone();
	icecream();
	topping();
	myRoll();
	glPopMatrix();
}
//--------------------------------------------------------------------

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance,
	_In_ LPSTR cmdLine, _In_ int nCmdShow) // FIXED
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	//gluPerspective(60.0, 1.0, -1.0, 1.0);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
	
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------