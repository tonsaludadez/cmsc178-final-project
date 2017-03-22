#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <time.h>
#include <iostream>

#include "controller.h"

//#define WINDOWWIDTH 640
//#define WINDOWHEIGHT 480
#define WINDOWWIDTH 1024
#define WINDOWHEIGHT 600
#define WINDOWPOSX 200
#define WINDOWPOSY 50

char title[] = "Mission Banana";
int refreshMillis = 100;

controller control;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

void display();
void idle();
void initGL();
void key(unsigned char, int, int);
void mouse(int, int, int, int);
void resetKeys();
void reshape(GLsizei, GLsizei);
void specialKey(int, int, int);
void timer(int);

int main(int argc, char** argv){
    srand((unsigned)time(0));

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowSize(WINDOWWIDTH, WINDOWHEIGHT);
	glutInitWindowPosition(WINDOWPOSX, WINDOWPOSY);


	glutCreateWindow(title);

	//Full screen mode
	//glutGameModeString("1024x600:32@60");
	//glutEnterGameMode();

    glEnable(GLUT_MULTISAMPLE);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutIdleFunc(idle);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(specialKey);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);

    initGL();

    glutMainLoop();

	return 0;
}

void initGL(){
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
     sound::playMain();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    control.gameStart();

    glutSwapBuffers();
}

void idle(){
    glutPostRedisplay();
}

void key(unsigned char key, int x, int y){
    switch(key){
    case 32:
        if(control.tutorialMode)
        {
            sound::playExplosion();
            control.tutorialMode = false;
            control.level = 1;
            control.isGame = true;
            control.GameClock.begTime = clock();
            control.Logic.falling_elapsed.begTime = clock();
            control.newGame();

            //sound::playMain();
        }

        if(control.gameOver)
        {
            control.level = 1;
            control.isGame = false;
            control.gameOver = false;
            control.life = 3;

            sound::playMain();
        }
//        if(control.isGame == false)
//        {
//            control.newGame();
//            control.GameClock.begTime = clock();
//            control.Logic.falling_elapsed.begTime = clock();
//        }
//
//        //control.Platform.randomizePlatformPos();
//        //std::cout<<"Space"<<std::endl;
        break;

    case 27:
        glutLeaveGameMode();
        exit(1);
    }
}

void mouse(int button, int state, int x, int y)
{
    float _x = (float)x/GLUT_WINDOW_X;
    float _y = (float)y/GLUT_WINDOW_Y;

    if(button == GLUT_LEFT_BUTTON)
    {
        //start game
        if(_x > 8.12 && _x < 9.62 && _y > 3.10 && _y < 3.31)
        {
            if(!control.isGame)
            {
                sound::playExplosion();
                control.newGame();
                control.GameClock.begTime = clock();
                control.Logic.falling_elapsed.begTime = clock();
            }
        }

        if(_x > 8.12 && _x < 9.62 && _y > 3.41 && _y < 3.68)
        {
            if(!control.isGame)
            {
                control.tutorialMode = true;
            }
        }

        if(_x > 8.12 && _x < 9.62 && _y > 3.71 && _y < 3.99)
        {
            //glutLeaveGameMode();
            exit(1);
        }
    }
    //std::cout<<_x<<" "<<_y<<std::endl;
}

void specialKey(int key, int x, int y){
    glutSetKeyRepeat(1);

    switch(key)
    {
    case GLUT_KEY_RIGHT:
        control.keys[key] = true;
        control.Logic.right_pressed = true;
        control.Logic.right_elapsed.begTime = clock();
        break;
    case GLUT_KEY_LEFT:
        control.keys[key] = true;
        control.Logic.left_pressed = true;
        control.Logic.left_elapsed.begTime = clock();
        break;
    case GLUT_KEY_UP:
        control.keys[key] = true;
        control.Logic.up_pressed = true;
        control.Logic.up_elapsed.begTime = clock();
        control.Logic.falling_elapsed.begTime = clock();
        //control.initLevel();
        break;
    }
}

/*void resetKeys(){
    int ctr;
    for(ctr = 0; ctr < 206; ctr++)
    {
        keys[ctr] = false;
    }
}*/

void reshape(GLsizei width, GLsizei height){
    if(height == 0)
        height = 1;

    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    //std::cout<<"Aspect: "<<aspect<<std::endl;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width >= height)
    {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else
    {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(refreshMillis, timer, 0);
}
