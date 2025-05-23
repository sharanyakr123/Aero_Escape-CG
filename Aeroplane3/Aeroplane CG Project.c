#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
GLfloat a=0,b=5,c=10,d=40,e=45,f=40,g=15,h=20,i=15; //x-co-ordinate of plane
GLfloat a1=310,b1=270,c1=290,d1=290,e1=280,f1=270,g1=290,h1=290,i1=310; //y co-ordinates of plane
GLfloat x11=470,x12=480,x13=600,x14=620,x15=590,x16=600,x17=650,x18=660,x19=610,x20=630,x21=580,x22=600; //x co-ordinates of obstacles
GLfloat y11=270,y12=290,y13=230,y14=250,y15=330,y16=350,y17=450,y18=470,y19=490,y20=510,y21=170,y22=190; // y co-ordinates of obstacles
GLint flag=0,flag1=0,flag2=0,flag3=0,flag5=1,flag4=0;
GLfloat sp1=0.05,sp2=0.07,sp3=0.0625;
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,600,0,600);
	glMatrixMode(GL_MODELVIEW);
}
/*void Reshape(int w,int h)
{
	glViewport(0,0,1366,400);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>h)
	gluOrtho2D(0,600,0,600);
	else
	gluOrtho2D(0,600,0,600);
	glMatrixMode(GL_MODELVIEW);
}*/
void drawstring(float x,float y,float z,char *string)
{
 char *c;
 glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
 {
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
 }
}
void screen()
{
	glColor3f(1.0,0.0,1.0);
	drawstring(210,540,0.0,"CGV MINI PROJECT ON Aero Escape");
	glColor3f(1.0,1.0,1.2);
	drawstring(180,420,0.0," ");
	drawstring(340,420,0,"-Sharanya shastri[1jt20cs089] ");
	drawstring(180,370,0.0," ");
	drawstring(340,370,0.0,"-Samanvitha.S[1jt20cs081] ");
	glColor3f(1.0,0.0,1.0);
	drawstring(230,320,0.0,"UNDER THE GUIDENCE OF");
	glColor3f(1.0,1.0,1.2);
	drawstring(260,280,0.0,"Prof:Naveen  ");
	glColor3f(0.0,0.8,1.0);
	drawstring(160,130,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	drawstring(230,80,0.0,"ACADEMIC YEAR: 2022-2023");
	glColor3f(rand()%2,rand()%3,rand()%2);
	drawstring(245,35,0.0,"Press 'b' to start the game");
glFlush();
}
void msg()
{
	glColor3f(1.0,0.2,0.0);
	drawstring(250,300,0.0,"CONGRATULATIONS");
	drawstring(250,250,0.0,"LEVEL COMPLETED");
	drawstring(250,200,0.0,"Press 'L' to start Next Level");
}
void msg1()
{
	glColor3f(1.0,0.6,0.6);
	drawstring(250,300,0.0,"GAME OVER RETRY");
	drawstring(250,270,0.0,"PRESS 'e' TO EXIT");
}
void msg2()
{
	glColor3f(1.0,0.6,0.6);
	drawstring(250,320,0.0,"GAME OVER");
	drawstring(250,280,0.0,"Player completed 1 level");
	drawstring(250,250,0.0,"PRESS 'e' TO EXIT");
}
void msg3()
{
	glColor3f(1.0,0.6,0.6);
	drawstring(250,320,0.0,"GAME OVER");
	drawstring(250,280,0.0,"Player completed 2 level");
	drawstring(250,250,0.0,"PRESS 'e' TO EXIT");
}

void plane()
{

	glColor3f(0.5,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(a,a1);
		glVertex2f(b,b1);
		glVertex2f(c,c1);
	glEnd();
	glColor3f(0.5,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(c,c1);
		glVertex2f(d,d1);
		glVertex2f(e,e1);
		glVertex2f(f,f1);
		glVertex2f(b,b1);
	glEnd();
	glColor3f(0.6,0.0,0.0);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(g,g1);
		glVertex2f(i,i1);
		glVertex2f(h,h1);
	glEnd();
	glutPostRedisplay();
}
void obstacle()
{
		glColor3f(rand()%100,0.44,rand()%50);
		glBegin(GL_POLYGON);
			glVertex2f(x11,y11);
			glVertex2f(x12,y11);
			glVertex2f(x12,y12);
			glVertex2f(x11,y12);
		glEnd();
		glColor3f(rand()%100,rand()%50,0.65);
		glBegin(GL_POLYGON);
			glVertex2f(x13,y13);
			glVertex2f(x14,y13);
			glVertex2f(x14,y14);
			glVertex2f(x13,y14);
		glEnd();
		glColor3f(0.7,rand()%100,rand()%200);
		glBegin(GL_POLYGON);
			glVertex2f(x15,y15);
			glVertex2f(x16,y15);
			glVertex2f(x16,y16);
			glVertex2f(x15,y16);
		glEnd();
		glColor3f(rand()%60,0.6,rand()%100);
		glBegin(GL_POLYGON);
			glVertex2f(x17,y17);
			glVertex2f(x18,y17);
			glVertex2f(x18,y18);
			glVertex2f(x17,y18);
		glEnd();
		glColor3f(rand()%70,rand()%200,rand()%300);
		glBegin(GL_POLYGON);
			glVertex2f(x19,y19);
			glVertex2f(x20,y19);
			glVertex2f(x20,y20);
			glVertex2f(x19,y20);
		glEnd();
		glColor3f(rand()%70,rand()%200,rand()%300);
		glBegin(GL_POLYGON);
			glVertex2f(x21,y21);
			glVertex2f(x22,y21);
			glVertex2f(x22,y22);
			glVertex2f(x21,y22);
		glEnd();

		glutPostRedisplay();

}

void moveup(void)
{
	glLoadIdentity();
	a1=a1+20;
	b1=b1+20;
	c1=c1+20;
	d1=d1+20;
	e1=e1+20;
	f1=f1+20;
	g1=g1+20;
	h1=h1+20;
	i1=i1+20;
	if(a1>600)
	flag2=1;
	glutPostRedisplay();
}

void movedown(void)
{
	glLoadIdentity();
	a1=a1-20;
	b1=b1-20;
	c1=c1-20;
	d1=d1-20;
	e1=e1-20;
	f1=f1-20;
	g1=g1-20;
	h1=h1-20;
	i1=i1-20;
	if(b1<0||f1<0)
	flag2=1;
	glutPostRedisplay();
}
void key(unsigned char k,int x,int y)
{
	switch(k)
	{

	case 'a':
			if(k=='a')
			moveup();
			break;
	case 's': if(k=='s')
	        movedown();
	        break;
	case 'b':flag=1;
			 flag1=1;

			 break;
	case 'e':
			 exit(0);
	case 'l':
			 flag5=1;
			 flag1=1;
				break;
}
}
void mov()
{	//PLANE MOV
	if(flag1==1)
	{

	if(a<600||b<600||c<600||d<600||e<600||f<600||g<600||h<600||i<600)
	{
		a=a+sp3;
		b=b+sp3;
		c=c+sp3;
		d=d+sp3;
		e=e+sp3;
		f=f+sp3;
		g=g+sp3;
		h=h+sp3;
		i=i+sp3;

	}

	//OBSTACLE MOV
	if(x11>=0||x12>=0)
	{
		x11=x11-sp1;
		x12=x12-sp1;
	}
	else
	{
		x11=600;
		x12=610;
		if(y11<590)
		{
		y11=y11+40;
		y12=y12+40;
		}
		else
		{
			y11=270;
			y12=290;
		}
	}
	if(x13>=0||x14>=0)
	{
		x13=x13-sp2;
		x14=x14-sp2;
	}
	else
	{
		x13=600;
		x14=620;
		if(y13<590)
		{
			y13=y13+40;
			y14=y14+40;
		}
		else
		{
			y13=230;
			y14=250;
		}
	}
	if(x15>=0||x16>=0)
	{
		x15=x15-sp1;
		x16=x16-sp1;
  	}
	else
	{
		x15=590;
		x16=600;
		if(y15<610)
		{
			y15+=40;
			y16+=40;
		}
		else
		{
			y15=330;
			y16=350;
		}
	}
	if(x17>=0||x18>=0)
	{
		x17=x17-sp1;
		x18=x18-sp1;
	}
	else
	{
		x17=650;
		x18=660;
		if(y17<610)
		{
			y17+=40;
			y18+=40;
		}
		else
		{
			y17=230;
			y18=250;
		}
	}
	if(x19>=0||x20>=0)
	{
		x19=x19-sp2;
		x20=x20-sp2;
	}
	else
	{
		x19=580;
		x20=600;
		if(y19<570)
		{
			y19+=40;
			y20+=40;
		}
		else
		{
			y19=170;
			y20=190;
		}
	}
	if(x21>=0||x22>=0)
	{
		x21=x21-sp2;
		x22=x22-sp2;
	}
	else
	{
		x21=580;
		x22=600;
		if(y21<610)
		{
			y21+=40;
			y22+=40;
		}
		else
		{
			y21=170;
			y22=190;
		}
	}


	//COLISSION
	if((d>x11&&d1==y12&&d<x12)||(f>x11&&f1==y11&&f<x12)||(d>x11&&d1==y11&&d<x12)||(f>x11&&f1==y12&&f<x12)||(c>x11&&c1==y12&&c<x12)||(b>x11&&b1==y12&&b<x12)||(c>x11&&c1==y11&&c<x12)||(b>x11&&b1==y12&&b<x12)||(a>x11&&a1==y11&&a<x12))
	flag2=1;

	else if((d>x13&&d1==y14&&d<x14)||(f>x13&&f1==y13&&f<x14)||(d>x13&&d1==y13&&d<x14)||(f>x13&&f1==y14&&f<x14)||(c>x13&&c1==y14&&c<x14)||(b>x13&&b1==y14&&b<x14)||(c>x13&&c1==y13&&c<x14)||(b>x13&&b1==y13&&b<x14)||(a>x13&&a1==y13&&a<x14))
	flag2=1;

	else if((d>x15&&d1==y16&&d<x16)||(f>x15&&f1==y15&&f<x16)||(d>x15&&d1==y15&&d<x16)||(f>x15&&f1==y16&&f<x16)||(c>x15&&c1==y16&&c<x16)||(b>x15&&b1==y16&&b<x16)||(c>x15&&c1==y15&&c<x16)||(b>x15&&b1==y15&&b<x16)||(a>x15&&a1==y15&&a<x16))
	flag2=1;

	else if((d>x17&&d1==y18&&d<x18)||(f>x17&&f1==y17&&f<x18)||(d>x17&&d1==y17&&d<x18)||(f>x17&&f1==y18&&f<x18)||(c>x17&&c1==y18&&c<x18)||(b>x17&&b1==y18&&b<x18)||(c>x17&&c1==y17&&c<x18)||(b>x17&&b1==y17&&b<x18)||(a>x17&&a1==y17&&a<x18))
	flag2=1;

	else if((d>x19&&d1==y20&&d<x20)||(f>x19&&f1==y19&&f<x20)||(d>x19&&d1==y19&&d<x20)||(f>x19&&f1==y20&&f<x20)||(c<x19&&c1==y20&&c>x20)||(b>x19&&b1==y20&&b<x20)||(c>x19&&c1==y19&&c<x20)||(b>x19&&b1==y19&&b<x20)||(a>x19&&a1==y19&&a<x20))
	flag2=1;

	else if((d>x21&&d1==y21&&d<x22)||(f>x21&&f1==y21&&f<x22)||(d>x21&&d1==y21&&d<x22)||(f>x21&&f1==y22&&f<x22)||(c<x21&&c1==y22&&c>x22)||(b>x21&&b1==y22&&b<x20)||(c>x21&&c1==y22&&c<x22)||(b>x21&&b1==y21&&b<x22)||(a>x21&&a1==y21&&a<x22))
	flag2=1;

	if(a>=600)
	{
		sp3=sp3+0.03125;
		sp1=sp1+0.07;
		sp2=sp2+0.08;
		if(sp3>0.125)
		{
			flag4=1;
		}
		a=0,b=5;c=10;d=40;e=45;f=40;g=15;h=20;i=15;
		a1=310;b1=270;c1=290;d1=290;e1=280;f1=270;g1=290;h1=290;i1=310;

		x11=470;x12=480;x13=520;x14=540;x15=590;x16=600;x17=650;x18=660;x19=610;x20=630,x21=580;x22=600;
		y11=270;y12=290;y13=230;y14=250;y15=330;y16=350;y17=450;y18=470;y19=490;y20=510;y21=170;y22=190;
		flag3=0;
		flag5=0;
	}
	}

	glutPostRedisplay();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);

	if(flag==0)
	{
		screen();
	}
	if(flag1==1)
	{
		plane();
		obstacle();

	}
	if(flag2==1&&sp3==0.0625)
	{
		flag1=0;
		msg1();
	}
	if(flag2==1&&sp3==0.09375)
	{
		flag1=0;
		msg2();
	}
	if(flag2==1&&sp3==0.125)
	{
		flag1=0;
		msg3();
	}
	if(flag5==0)
	{
		flag1=0;
		msg();
		flag3=1;
	}
	if(flag4==1)
	{
		flag=1;
		flag1=0;
		flag2=0;
		flag5=1;
		drawstring(250,330,0.0,"Congrats");
		drawstring(210,300,0.0,"Player Completes All 3 Levels");
	}
	glFlush();

}
int main (int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("plane");
	init();

	glutDisplayFunc(display);
	//glutReshapeFunc(Reshape);
	glutIdleFunc(mov);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}
