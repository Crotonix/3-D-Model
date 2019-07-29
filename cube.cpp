#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

static GLfloat vertex[8][3] = {
	{ 0.0, 0.0, 0.0 }, { 10.0, 0.0, 0.0 }, { 10.0, 10.0, 0.0 }, { 0.0, 10.0, 0.0 },
	{ 0.0, 0.0, 10.0 }, { 10.0, 0.0, 10.0 }, { 10.0, 10.0, 10.0 }, { 0.0, 10.0, 10.0 }
};

static GLfloat normal[6][3] = {
	{ 0.0, 0.0, -1.0 }, { 0.0, 0.0, 1.0 },
	{ 1.0, 0.0, 0.0 }, { -1.0, 0.0, 0.0 },
	{ 0.0, 1.0, 0.0 }, { 0.0, -1.0, 0.0 }
};

static GLubyte allIndices[] = { 0, 1, 2, 3, 7, 6, 5, 4,
1, 5, 6, 2, 0, 3, 7, 4,
3, 2, 6, 7, 0, 4, 5, 1
};

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glVertexPointer(3, GL_FLOAT, 0, vertex);
	glNormalPointer(GL_FLOAT, 0, normal);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
	//glDisableClientState(GL_VERTEX_ARRAY);
	//glDisableClientState(GL_NORMAL_ARRAY);
	/*glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 3.0);
	glVertex2f(4.0, 3.0);
	glVertex2f(6.0, 1.5);
	glVertex2f(4.0, 0.0);
	glEnd();*/
	glFlush();
}

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glOrtho(0.0, 20.0, 0.0, 20.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
}

void reshape(int w, int h)
{
	//glScalef(7.0, 7.0, 7.0);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(10.0, (GLdouble)w, 10.0, (GLdouble)h);
	//glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
