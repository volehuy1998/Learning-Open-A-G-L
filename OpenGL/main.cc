#include <GL/glut.h>

int windowWidth = 400;
int windowHeight = 400;

/*
 * -lGL
 *		glFlush
 * 		glClear
 *		glRotatef
 *		glViewport
 *		GL_COLOR_BUFFER_BIT
 * -lglut
 *		glutInit
 *		glutInitDisplayMode
 * 		glutInitWindowPosition
 *		glutInitWindowSize
 *		glutDisplayFunc
 *		glutPostRedisplay
 *		glutMainLoop
 *		glutWireTeapot
 *		glutSwapBuffers
 *		glutIdleFunc
 *		glutReshapeFunc
 *		GLUT_DOUBLE
*/

void render()
{
	// Clear with black color
	glClear(GL_COLOR_BUFFER_BIT);
	// Rotate Z axis
	glRotatef(
		0.1,	// angle
		0, 0, 1 // x,y,z
	);
	// Request wire tea-pot image to display
	glutWireTeapot(1);
	// glFlush: Forces exec of OpenGL func in finite time 
	// glFlush()
	// glutSwapBuffers() replace glFlush()
	glutSwapBuffers();
}

void idle()
{
	// Marks the current window as needing to be redisplayed
	// or not rotate wire tea-pot
	glutPostRedisplay();
}

void reshape(int width, int height)
{
	// resize window 
	glViewport(
		0, 0, 
		width, height
	);
	windowWidth = width;
	windowHeight = height;
}


int main(int argc, char *argv[])
{
	glutInit(
		&argc,
		argv
	);
	// Double buffer: visible to display, invisible to prepair
	glutInitDisplayMode(GLUT_DOUBLE);
	// Init window position
	glutInitWindowPosition(0,0);
	// Init window size
	glutInitWindowSize(400,400);
	// Init window title
	glutCreateWindow("First");
	// Callback render
	glutDisplayFunc(render);
	// When idle, call idle func
	glutIdleFunc(idle);
	// Call when resize window
	glutReshapeFunc(reshape);
	// Loop for render, event
	glutMainLoop();
	return 0;
}
