#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "OpenGL Window"

float speed = 0.0;
int open = 0, close = 0;
float transf = 29;
int x = 0, y = 0, z = 0;
int x2 = 0, y2 = 0, z2 = 0;
float speed2 = 0.1, speed3 = -0.1;
float sizeFrame = 40.0;
int e = 0;

float rotateAngle = 0.0f;
float viewDistance = -60.0;
float rotateY = 0.0f;
void sun();
LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == 0x4F) //O key
		{
			open = 1;
		}
		else if (wParam == 0x43) //C key
		{
			close = 1;
		}
		else if (wParam == VK_UP) {
			viewDistance += 10.0f;
		}
		else if (wParam == VK_DOWN) {
			viewDistance -= 10.0f;
		}
		else if (wParam == VK_LEFT) {
			rotateY -= 10.0f;
		}
		else if (wParam == VK_RIGHT) {
			rotateY += 10.0f;
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
//--------------------------------------------------------------------

void tower1() {

	glBegin(GL_QUADS);
	glColor3ub(153, 76, 0);
	glVertex3f(-6, 25, 3);
	glVertex3f(6, 25, 3);
	glVertex3f(6, 15, 3);
	glVertex3f(-6, 15, 3);

	glVertex3f(-6, 15, 3);
	glVertex3f(-6, 15, -3);
	glVertex3f(6, 15, -3);
	glVertex3f(6, 15, 3);

	glVertex3f(6, 15, 3);
	glVertex3f(6, 15, -3);
	glVertex3f(6, 25, -3);
	glVertex3f(6, 25, 3);

	glVertex3f(6, 25, 3);
	glVertex3f(6, 25, -3);
	glVertex3f(-6, 25, -3);
	glVertex3f(-6, 25, 3);

	glVertex3f(-6, 25, 3);
	glVertex3f(-6, 15, 3);
	glVertex3f(-6, 15, -3);
	glVertex3f(-6, 25, -3);

	glVertex3f(-6, 25, -3);
	glVertex3f(6, 25, -3);
	glVertex3f(6, 15, -3);
	glVertex3f(-6, 15, -3);
	glEnd();
}

void tower2() {
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	glColor3ub(204, 102, 0);
	gluCylinder(cylinder, .5, .5, 25, 35, 8);

	gluDeleteQuadric(cylinder);
}

void tower3() {
	glBegin(GL_QUADS);
	glColor3ub(102, 51, 0);
	glVertex3f(-1, 30, .5);
	glVertex3f(1, 30, .5);
	glVertex3f(6, 25, 3);
	glVertex3f(-6, 25, 3);

	glVertex3f(-6, 25, 3);
	glVertex3f(-6, 25, -3);
	glVertex3f(6, 25, -3);
	glVertex3f(6, 25, 3);

	glVertex3f(6, 25, 3);
	glVertex3f(6, 25, -3);
	glVertex3f(1, 30, -.5);
	glVertex3f(1, 30, .5);

	glVertex3f(1, 30, .5);
	glVertex3f(1, 30, -.5);
	glVertex3f(-1, 30, -.5);
	glVertex3f(-1, 30, .5);

	glVertex3f(-1, 30, .5);
	glVertex3f(-6, 25, 3);
	glVertex3f(-6, 25, -3);
	glVertex3f(-1, 30, -.5);

	glVertex3f(-1, 30, -.5);
	glVertex3f(1, 30, -.5);
	glVertex3f(6, 25, -3);
	glVertex3f(-6, 25, -3);
	glEnd();
}

void tower4() {
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	glColor3ub(102, 51, 0);
	gluCylinder(cylinder, .5, .0, 3, 35, 8);

	gluDeleteQuadric(cylinder);
}

void tower5() {
	glBegin(GL_TRIANGLES);
	glColor3ub(102, 51, 0);
	glVertex3f(0, 31, 0);
	glVertex3f(-1, 30, .5);
	glVertex3f(1, 30, .5);

	glVertex3f(1, 30, .5);
	glVertex3f(0, 31, 0);
	glVertex3f(1, 30, -.5);

	glVertex3f(1, 30, -.5);
	glVertex3f(0, 31, 0);
	glVertex3f(-1, 30, -.5);

	glVertex3f(-1, 30, -.5);
	glVertex3f(0, 31, 0);
	glVertex3f(-1, 30, .5);
	glEnd();
}

void tower6() {
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	glColor3ub(204, 102, 0);
	gluCylinder(cylinder, .5, .5, 2, 35, 8);

	gluDeleteQuadric(cylinder);
}

void tower7() {
	glBegin(GL_QUADS);
	glColor3ub(153, 76, 0);
	glVertex3f(-6, 15, 3);
	glVertex3f(6, 15, 3);
	glVertex3f(6, 0, 3);
	glVertex3f(-6, 0, 3);

	glVertex3f(-6, 0, 3);
	glVertex3f(-6, 0, -3);
	glVertex3f(6, 0, -3);
	glVertex3f(6, 0, 3);

	glVertex3f(6, 0, 3);
	glVertex3f(6, 0, -3);
	glVertex3f(6, 15, -3);
	glVertex3f(6, 15, 3);

	glVertex3f(6, 15, 3);
	glVertex3f(6, 15, -3);
	glVertex3f(-6, 15, -3);
	glVertex3f(-6, 15, 3);

	glVertex3f(-6, 15, 3);
	glVertex3f(-6, 0, 3);
	glVertex3f(-6, 0, -3);
	glVertex3f(-6, 15, -3);

	glVertex3f(-6, 15, -3);
	glVertex3f(6, 15, -3);
	glVertex3f(6, 0, -3);
	glVertex3f(-6, 0, -3);
	glEnd();
}

void road1() {

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(6, 10, 4);
	glVertex3f(6, 10, 24);
	glVertex3f(6, 9, 24);
	glVertex3f(6, 9, 4);

	glVertex3f(6, 9, 4);
	glVertex3f(-6, 9, 4);
	glVertex3f(-6, 9, 24);
	glVertex3f(6, 9, 24);

	glVertex3f(6, 9, 24);
	glVertex3f(-6, 9, 24);
	glVertex3f(-6, 10, 24);
	glVertex3f(6, 10, 24);

	glVertex3f(6, 10, 24);
	glVertex3f(-6, 10, 24);
	glVertex3f(-6, 10, 4);
	glVertex3f(6, 10, 4);

	glVertex3f(6, 10, 4);
	glVertex3f(6, 9, 4);
	glVertex3f(-6, 9, 4);
	glVertex3f(-6, 10, 4);

	glVertex3f(-6, 10, 4);
	glVertex3f(-6, 10, 24);
	glVertex3f(-6, 9, 24);
	glVertex3f(-6, 9, 4);
	glEnd();
}

void roadRope() {
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3ub(96, 96, 96);
	for (int i = 45.0; i < 115.0; i++)
	{
		glVertex2f(0 + 5 * cos(i * -3.142 / 180), -0 + 6 * sin(i * -3.142 / 180));
	}
	glEnd();
}

void upperBridge() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(-12, 20.5, 6.5);
	glVertex3f(12, 20.5, 6.5);
	glVertex3f(12, 20, 6.5);
	glVertex3f(-12, 20, 6.5);

	glVertex3f(-12, 20, 6.5);
	glVertex3f(-12, 20, 2.5);
	glVertex3f(12, 20, 2.5);
	glVertex3f(12, 20, 6.5);

	glVertex3f(12, 20, 6.5);
	glVertex3f(12, 20, 2.5);
	glVertex3f(12, 20.5, 2.5);
	glVertex3f(12, 20.5, 6.5);

	glVertex3f(12, 20.5, 6.5);
	glVertex3f(12, 20.5, 2.5);
	glVertex3f(-12, 20.5, 2.5);
	glVertex3f(12, 20.5, 6.5);

	glVertex3f(12, 20.5, 6.5);
	glVertex3f(-12, 20, 6.5);
	glVertex3f(-12, 20, 2.5);
	glVertex3f(-12, 20.5, 2.5);

	glVertex3f(-12, 20.5, 2.5);
	glVertex3f(12, 20.5, 2.5);
	glVertex3f(12, 20, 2.5);
	glVertex3f(-12, 20, 2.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(-12, 20.5, -6.5);
	glVertex3f(12, 20.5, -6.5);
	glVertex3f(12, 20, -6.5);
	glVertex3f(-12, 20, -6.5);

	glVertex3f(-12, 20, -6.5);
	glVertex3f(-12, 20, -2.5);
	glVertex3f(12, 20, -2.5);
	glVertex3f(12, 20, -6.5);

	glVertex3f(12, 20, -6.5);
	glVertex3f(12, 20, -2.5);
	glVertex3f(12, 20.5, -2.5);
	glVertex3f(12, 20.5, -6.5);

	glVertex3f(12, 20.5, -6.5);
	glVertex3f(12, 20.5, -2.5);
	glVertex3f(-12, 20.5, -2.5);
	glVertex3f(12, 20.5, -6.5);

	glVertex3f(12, 20.5, -6.5);
	glVertex3f(-12, 20, -6.5);
	glVertex3f(-12, 20, -2.5);
	glVertex3f(-12, 20.5, -2.5);

	glVertex3f(-12, 20.5, -2.5);
	glVertex3f(12, 20.5, -2.5);
	glVertex3f(12, 20, -2.5);
	glVertex3f(-12, 20, -2.5);
	glEnd();
}

void movableBridge() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(0, 0, 6);
	glVertex3f(11, 0, 6);
	glVertex3f(11, 1, 6);
	glVertex3f(0, 1, 6);

	glVertex3f(0, 1, 6);
	glVertex3f(0, 1, -6);
	glVertex3f(11, 1, -6);
	glVertex3f(11, 1, 6);

	glVertex3f(11, 1, 6);
	glVertex3f(11, 1, -6);
	glVertex3f(11, 0, -6);
	glVertex3f(11, 0, 6);

	glVertex3f(11, 0, 6);
	glVertex3f(11, 0, -6);
	glVertex3f(0, 0, -6);
	glVertex3f(0, 0, 6);

	glVertex3f(0, 0, 6);
	glVertex3f(0, 1, 6);
	glVertex3f(0, 1, -6);
	glVertex3f(0, 0, -6);

	glVertex3f(0, 0, -6);
	glVertex3f(11, 0, -6);
	glVertex3f(11, 1, -6);
	glVertex3f(0, 1, -6);
	glEnd();
}

void combine1() {
	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 25, 3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 25, -3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 25, -3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 25, 3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 27, 3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 27, -3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 27, -3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 27, 3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 0, 3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 0, -3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 0, -3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 0, 3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);

	tower7();
	tower5();
	tower3();
	tower1();
	glPopMatrix();
}

void combine2() {
	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 25, 3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 25, -3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 25, -3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 25, 3);
	glRotatef(-90, 1, 0, 0);
	tower6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 27, 3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 27, -3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 27, -3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 27, 3);
	glRotatef(-90, 1, 0, 0);
	tower4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 0, 3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(6, 0, -3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 0, -3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 0, 3);
	glRotatef(-90, 1, 0, 0);
	tower2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glRotatef(90, 0, 1, 0);

	tower7();
	tower5();
	tower3();
	tower1();
	glPopMatrix();
}

void combine3() {
	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	road1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-43, 0, 0);
	glRotatef(90, 0, 1, 0);
	road1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 6);
	glScalef(3.5, 3.5, 0);
	glTranslatef(-8.8, 10, 0);
	roadRope();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -6);
	glScalef(3.5, 3.5, 0);
	glTranslatef(-8.8, 10, 0);
	roadRope();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -6);
	glRotatef(180, 0, 1, 0);
	glScalef(3.5, 3.5, 0);
	glTranslatef(-8.8, 10, 0);
	roadRope();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 6);
	glRotatef(180, 0, 1, 0);
	glScalef(3.5, 3.5, 0);
	glTranslatef(-8.8, 10, 0);
	roadRope();
	glPopMatrix();
}

void combine4() {
	upperBridge();

	if (open >= 1) {
		close = 0;
		speed += 0.10;
		transf -= 0.032;
		if (speed >= 45) {
			open = 0;
			transf = 12;
			speed = 45;
		}
	}
	else if (close >= 1) {
		open = 0;
		speed -= 0.10;
		transf += 0.032;
		if (speed <= 0) {
			close = 0;
			speed = 0;
			transf = 29;
		}
	}

	glPushMatrix();
	glTranslatef(0, transf, 0);
	sun();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(-11, 9, 0);
	glRotatef(speed, 0, 0, 1);
	movableBridge();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11, 9, 0);
	glRotatef(speed, 0, 0, 1);
	movableBridge();
	glPopMatrix();


}

void sun() {

	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();
	glColor3ub(255, 165, 0);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, 6, 30, 30);
	gluDeleteQuadric(sphere);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(0.0, -10.0, viewDistance);
	glRotatef(rotateY, 0, 1, 0);
	glPushMatrix();

	combine1();
	combine2();
	combine3();
	combine4();

	glPopMatrix();

}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
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
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,
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

	gluPerspective(70, 1, 1, 2000);

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
