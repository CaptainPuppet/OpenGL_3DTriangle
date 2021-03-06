#include <windows.h> //the windows include file, required by all windows applications

#include <gl\glut.h> //the glut file for windows operations
// it also includes gl.h and glu.h for the openGL library calls
#include "utils.h"  


GLfloat P1[3] = { 0.5,0.,0.5 };
GLfloat P2[3] = { 0.,0.,-0.5 };
GLfloat P3[3] = { -0.5,0.,0.5 };
GLfloat u[3], v[3], uv[3];

GLfloat ang = 0;

GLfloat Speed = 5;

void myPyramid() {

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(P1);
	glVertex3fv(uv);
	glVertex3fv(P3);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(P1);
	glVertex3fv(P2);
	glVertex3fv(uv);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(P3);
	glVertex3fv(uv);
	glVertex3fv(P2);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(P3);
	glVertex3fv(P2);
	glVertex3fv(P1);
	glEnd();
}


void Display(void)
{


	glClear(GL_COLOR_BUFFER_BIT);



	glColor3f(1.0, 1.0, 1.0);
	glPointSize(5.);

	glBegin(GL_POINTS);
	glVertex3fv(P1);
	glVertex3fv(P2);
	glVertex3fv(P3);
	glVertex3fv(uv);
	glEnd();

	myPyramid();



	glFlush();
	glutSwapBuffers();
	//glRotatef(1, 0., 1., 0.);
	//	glRotatef(1,0.,0.,1.);
	glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y) {


	switch (key) {
		
	case '1':
		glRotatef(1, 1, 0., 0.);
		
		break;
	case '2':
		glRotatef(1, -1, 0., 0.);

		break;
	case '3':
		glRotatef(1, 0., 1, 0.);

		break;
	case '4':
		glRotatef(1, 0., -1, 0.);

		break;
	case '5':
		glRotatef(1, 0., 0., 1);

		break;
	case '6':
		glRotatef(1, 0., 0., -1);

		break;
		// exit on esc
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}



void reshape(int w, int h)
{
	// on reshape and on startup, keep the viewport to be the entire size of the window
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60., (GLfloat)w / h, 1., 20.);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.2, 0.2, 3, 0, 0, -100, 0., 1., 0.);

}


void init(void) {

	//set the clear color to be black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT, GL_FILL);

	vecsub(P1, P2, u);
	vecsub(P1, P3, v);
	crossproduct(u, v, uv);

}


void main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(320, 200);
	glutCreateWindow("Displaying 3D shapes");
	init();
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}