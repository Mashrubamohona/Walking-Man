#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
double incx=-300, incy;
double ang1=0;
double ang2=0;
double x=0;
int state;
struct point
{
	double x,y,z;
};




void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 400,0,0);
			glVertex3f(-400,0,0);

			glVertex3f(0,-400,0);
			glVertex3f(0, 400,0);

			glVertex3f(0,0, 400);
			glVertex3f(0,0,-400);
		}glEnd();
	}
}




void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}


void drawCircle(double radius,int segments)
{
    int i;
    struct point points[100];
    glColor3f(0.7,0.7,0.7);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0;i<segments;i++)
    {
        glBegin(GL_LINES);
        {
			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i+1].x,points[i+1].y,0);
        }
        glEnd();
    }
}


void draw_rec()
{
    glTranslatef(incx,0,0);


    glPushMatrix();
    glColor3f(0,1,1);
    glTranslatef(0,70,0);
    drawSquare(15);
	glPopMatrix();

	glPushMatrix();
    glColor3f(0,.2,1);
    glTranslatef(0,65,0);
    drawSquare(1);
    glPushMatrix();

    glColor3f(0,0,1);
    glRotatef(ang2,0,0,1);
    glTranslatef(0,-100,0);

    glBegin(GL_QUADS);{

		glVertex3f( 6, 80,2);
		glVertex3f( 6,10,2);
		glVertex3f(-6,10,2);
		glVertex3f(-6, 80,2);
	}glEnd();
    glPopMatrix();

    glPushMatrix();

    glColor3f(0,.5,1);
    glRotatef(-ang1,0,0,1);
    glTranslatef(0,-100,0);

    glBegin(GL_QUADS);{

		glVertex3f( 6, 80,2);
		glVertex3f( 6,10,2);
		glVertex3f(-6,10,2);
		glVertex3f(-6, 80,2);
	}glEnd();
    glPopMatrix();
	glPopMatrix();


    glPushMatrix();
    glBegin(GL_QUADS);{
        int a=20;
		glVertex3f( 20, 50,2);
		glVertex3f( 20,-a,2);
		glVertex3f(-20,-a,2);
		glVertex3f(-20, 50,2);
	}glEnd();
    glPopMatrix();

    glPushMatrix();

    glColor3f(0,0,1);
    glRotatef(ang1,0,0,1);
    glTranslatef(0,-100,0);

    glBegin(GL_QUADS);{

		glVertex3f( 6, 80,2);
		glVertex3f( 6,10,2);
		glVertex3f(-6,10,2);
		glVertex3f(-6, 80,2);
	}glEnd();
    glPopMatrix();

    glPushMatrix();

    glColor3f(0,.5,1);
    glRotatef(-ang1,0,0,1);
    glTranslatef(0,-100,0);

    glBegin(GL_QUADS);{

		glVertex3f( 6, 80,2);
		glVertex3f( 6,10,2);
		glVertex3f(-6,10,2);
		glVertex3f(-6, 80,2);
	}glEnd();
    glPopMatrix();





}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':
			drawgrid=1-drawgrid;
			break;

		default:
			break;
	}
}


void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			cameraHeight -= 3.0;
			break;
		case GLUT_KEY_UP:		// up arrow key
			cameraHeight += 3.0;
			break;

		case GLUT_KEY_RIGHT:
			cameraAngle += 0.03;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle -= 0.03;
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				drawaxes=1-drawaxes;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}



void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,400,	00,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	//add objects

	drawAxes();
    //drawSS();
    draw_rec();






	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}


void animate(){


	//codes for any changes in Models, Camera
    if(state ==0 && ang1>30){ state =1;}
    if(state ==1 && ang1 <-30){state =0;}

    if(state == 0) ang1+=0.05;
    else ang1-=0.05;

	glutPostRedisplay();

	if(state ==0 && ang2>50){ state =1;}
    if(state ==1 && ang2 <-50){state =0;}

    if(state == 0) ang2+=0.06;
    else ang2-=0.06;

            incx+=0.01;






	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}


