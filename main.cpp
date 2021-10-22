
#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include <glut.h>
static double x1=0.0;
static double x2=0.0;  // Rotates Blades
static double a1=0.0;
static double r1=0.0;     //tilt plane
static double r2=0.0;
static double r3=0.0;     //tilt plane
static double r4=0.0;

static double move=0.0;     // moves planes
static double move_y=0.0;     // moves planes

static double z1=0.0;   // Moves Cirlces

void
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(-2.5, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void Circle(){

glColor3f(1.0,1.0,1.0);
glutSolidTorus(0.4,3.5,100,100);

}


void drawPlane(){


/***********  PLANE CONSTRUCTION  *******************/
	glPushMatrix();


	// Main Body
glPushMatrix();
glScalef(.3,0.3,1.5);
glColor3f(1,1.0,0.5);
glutSolidSphere(2.0,50,50);
glPopMatrix();

 glPushMatrix();
 glTranslatef(0.0,0.1,-1.8);
glScalef(1.0,1,1.5);
glColor3f(0,0,1);
glutSolidSphere(0.5,25,25);
glPopMatrix();


//Left Fin

glPushMatrix();
glTranslatef(-1.0,0,0);
glScalef(1.5,0.1,0.5);
glColor3f(0,0,0);
glutSolidSphere(1.0,50,50);
glPopMatrix();

// Right Fin
glPushMatrix();

glTranslatef(1.0,0,0);
glScalef(1.5,0.1,0.5);
glColor3f(0,0,0);
glutSolidSphere(1.0,50,50);
glPopMatrix();

//right Tail fin
glPushMatrix();

glTranslatef(0.8,0,2.4);
glScalef(1.2,0.1,0.5);
glColor3f(0.0,0,0);
glutSolidSphere(0.4,50,50);
glPopMatrix();

//left Tail fin
glPushMatrix();
glTranslatef(-0.8,0,2.4);
glScalef(1.2,0.1,0.5);
glColor3f(0.0,0,0);
glutSolidSphere(0.4,50,50);
glPopMatrix();

//Top tail fin
glPushMatrix();
glTranslatef(0,0.5,2.4);
glScalef(0.1,1.1,0.5);
glColor3f(0.0,0,0);
glutSolidSphere(0.4,50,50);
glPopMatrix();

// Blades
glPushMatrix();
glRotatef(x2,0.0,0.0,1.0);
glPushMatrix();
glTranslatef(0,0.0,-3.0);
glScalef(1.5,0.2,0.1);
glColor3f(0.0,0,0);
glutSolidSphere(0.3,50,50);
glPopMatrix();

//blades
glPushMatrix();
glRotatef(90,0.0,0.0,1.0);
glTranslatef(0,0.0,-3.0);
glScalef(1.5,0.2,0.1);
glColor3f(0.0,0,0);
glutSolidSphere(0.3,50,50);
glPopMatrix();

glPopMatrix();
/* Blased End */

/*   Wheels   */
//Front


glPushMatrix();
glTranslatef(0.0,-0.8,-1.5);
glRotatef(90,0.0,1,0);
glScaled(0.3,0.3,0.3);
glutSolidTorus(0.18,0.5,25,25);
glColor3f(1,1,1);
glutSolidTorus(0.2,0.1,25,25);

glPopMatrix();

glPushMatrix();
glTranslatef(0.0,-0.4,-1.5);
glRotatef(20,0.0,1,0);
glScaled(0.05,0.3,0.05);
glutSolidSphere(1.0,25,25);
glPopMatrix();


//Rear

glPushMatrix();
glTranslatef(0.3,-0.8,0.7);
glRotatef(90,0.0,1,0);
glScaled(0.3,0.3,0.3);
glColor3f(0,0,0);
glutSolidTorus(0.18,0.5,25,25);
glColor3f(1,1,1);
glutSolidTorus(0.2,0.1,25,25);
glPopMatrix();

glPushMatrix();
glTranslatef(0.3,-0.4,0.7);
glRotatef(20,0.0,1,0);
glScaled(0.05,0.3,0.05);
glutSolidSphere(1.0,25,25);
glPopMatrix();

//rear 2
glPushMatrix();
glTranslatef(-0.3,-0.8,0.7);
glRotatef(90,0.0,1,0);
glScaled(0.3,0.3,0.3);
glColor3f(0,0,0);
glutSolidTorus(0.18,0.5,25,25);
glColor3f(1,1,1);
glutSolidTorus(0.2,0.1,25,25);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.3,-0.4,0.7);
glRotatef(20,0.0,1,0);
glScaled(0.05,0.3,0.05);
glutSolidSphere(1.0,25,25);
glPopMatrix();



glPopMatrix();



}

void plane(){

	glClearColor(0.3,0.3,0.3,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);

	glPushMatrix();
	glRotatef(x1,0.0,1.0,0.0);
	drawPlane();
	glPopMatrix();

glFlush();
glutSwapBuffers();

}
void gameOver(){
	glClearColor(1.0,0.0,0.0,0.0);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
	stroke_output(-2,2,"you crashed my plane");








glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
glVertex3f(-100,-5,100);
glVertex3f(100,-5,100);
glVertex3f(100,-5,-100);
glVertex3f(-100,-5,-100);
glEnd();

	glFlush();

}

void fighterPlane()
{


	glClearColor(0.3,0.3,0.3,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
if(move_y<=-4)
{
	gameOver();

}
else{

//Floor

glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
glVertex3f(-100,-5,100);
glVertex3f(100,-5,100);
glVertex3f(100,-5,-100);
glVertex3f(-100,-5,-100);
glEnd();


// draw the obstacles
glPushMatrix();
glTranslatef(0,0,-20+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(-3,0,-60+z1);
Circle();
glPopMatrix();

glPushMatrix();
glTranslatef(3,0,-100+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(0,0,-160+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(3,0,-320+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(-3,0,-380+z1);
Circle();
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-400+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(-3,0,-420+z1);
Circle();
glPopMatrix();

glPushMatrix();
glTranslatef(3,0,-440+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(0,0,-460+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(3,0,-500+z1);
Circle();
glPopMatrix();


glPushMatrix();
glTranslatef(-3,0,-530+z1);
Circle();
glPopMatrix();







// Call drawPlane

glPushMatrix();
	glTranslatef(move,-1.0+move_y,0);
	glRotatef(r1,0.0,0.0,1.0);
	glRotatef(r2,1.0,0.0,0.0);
	drawPlane();
	glPopMatrix();

}
	glFlush();
    glutSwapBuffers();
}






void s()
{x1+=0.3;
fighterPlane();
}

void start(){
x1+=0.3;
x2+=5.0;
z1+=0.5;
fighterPlane();
}

void p1(){

x2+=10.0;
plane();
}


void doInit()
{

	/* Background and foreground color */
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(.0,1.0,1.0);
    glViewport(0,0,640,480);

	/* Select the projection matrix and reset it then
     setup our view perspective */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);
    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
	glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LEQUAL);
}

void doDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-13.0f);
glPushMatrix();
	glScaled(0.7,0.7,0.7);
	stroke_output(-2.0, 1.7, "Wel Come");
	stroke_output(-2.0, 0.9, "To");
	stroke_output(-2.0, 0.0, "Project Created");
	stroke_output(-2.0, -0.9, "By");
	stroke_output(-2.0, -1.8, "Zaryab Shabir");
glPopMatrix();
	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
	GLfloat light_position3[]={0.0f,5.0f,5.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);


	glFlush();
	glutSwapBuffers();

}



void mykey(unsigned char key,int x,int y)
{
	if(key=='s' || key=='S')
	{
		glutIdleFunc(start);
	}


	if(key=='s' || key=='S')
	{
		r1=0;
	r2=-10;
	 //lower the nose of plane
		move_y-=0.5;;
	}



	if(key=='a'|| key=='A')
	{
		r1=45;
		r2=10;
		move-=0.1;
	}


	if(key=='d'|| key=='D')
	{
		r1=-45;
		r2=10;
		move+=0.1;
	}

	if(key=='w'|| key=='W')
	{
		 move_y+=0.5;
	r1=0;
	r2=10;
	}


	if(key=='p'|| key=='P')
	{
		x1+=1.3;
		glutIdleFunc(p1);

	}

	if(key=='o'|| key=='O')
	{
		x1-=1.3;
		glutIdleFunc(p1);

	}



	if(key=='q'|| key=='Q'){
	exit(0);

	}

}

static void specialKey(int key,int x,int y){

	if(key==GLUT_KEY_UP){
    move_y+=0.5;
	r1=0;
	r2=10;


	}


if(key==GLUT_KEY_DOWN){
	r1=0;
	r2=-10;
	 //lower the nose of plane
		move_y-=0.5;
	 // raise the nose of plane
	}
if(key==GLUT_KEY_LEFT){
	r1=45;
		r2=10;
		move-=0.1;

	}
if(key==GLUT_KEY_RIGHT){

	r1=-45;
		r2=10;
		move+=0.1;
	}



}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(30,0);
    glutCreateWindow("StuntPlane");
    glutDisplayFunc(doDisplay);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutKeyboardFunc(mykey);
	glutSpecialFunc(specialKey);
	doInit();
    glutMainLoop();
	return 0;
}
