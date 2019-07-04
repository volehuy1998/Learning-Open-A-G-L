#include <GL/glut.h>

void render()
{
	// Clear with black color
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(
		0.1,	// angle
		0, 0, 1 // x,y,z
	);
	// Display wire tea-pot
	glutWireTeapot(1);
	// Forces exec of OpenGL func in finite time 
	glFlush();
}

void idle()
{
	// Marks the current window as needing to be redisplayed
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(
		&argc,
		argv
	);
	// Init window position
	glutInitWindowPosition(0,0);
	// Init window size
	glutInitWindowSize(400,400);
	// Init window title
	glutCreateWindow("First");
	// Callback render
	glutDisplayFunc(render);
	glutIdleFunc(idle);
	// Loop for render, event
	glutMainLoop();
	return 0;
}
