//cube
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

static GLfloat vertex[8][3] = {
	{ 0.0, 0.0, 0.0 }, { 100.0, 0.0, 0.0 }, { 100.0, 100.0, 0.0 }, { 0.0, 100.0, 0.0 },
	{ 0.0, 0.0, 100.0 }, { 100.0, 0.0, 100.0 }, { 100.0, 100.0, 100.0 }, { 0.0, 100.0, 100.0 }
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

static GLfloat colors[] = { 1.0, 0.2, 0.2,
0.2, 0.2, 1.0,
0.8, 1.0, 0.2,
0.75, 0.75, 0.75,
0.35, 0.35, 0.35,
0.5, 0.5, 0.5,
0.5, 0.25, 0.25,
0.75, 0.35, 0.76
};


void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glColorPointer(3, GL_FLOAT, 0, colors);
	glVertexPointer(3, GL_FLOAT, 0, vertex);
	glNormalPointer(GL_FLOAT, 0, normal);
	glTranslatef(10.0, 10.0, 0.0);
	glRotatef(30.0, 0.0, 0.0, 50.0);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
	glFlush();
}

void init(void)
{
	glClearColor(0.0, 1.0, 0.57, 0.0);
	glOrtho(0.0, 20.0, 0.0, 20.0, -1.0, 1.0);
	glShadeModel(GL_SMOOTH);

	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 10.0, 10.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
}

void reshape(int w, int h)
{
	//glScalef(7.0, 7.0, 7.0);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLfloat)w / (GLfloat)h, 1.0, 10.0);
	gluOrtho2D(-150.0, (GLdouble)w, -150.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
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
