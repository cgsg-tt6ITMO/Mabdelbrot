/**/

#include <stdlib.h>
#include <string.h> // memcpy

#include "glut.h"
#include "CMPL.H"

#define FRAME_W 100
#define FRAME_H 100

#define X0 -1
#define Y0 -1
#define X1 1
#define Y1 1

byte Frame[FRAME_H][FRAME_W][3];

double Zoom = 10;

void PutPixel( int X, int Y, int R, int G, int B )
{
  if (X < 0 || X >= FRAME_W || Y < 0 || Y > FRAME_H)
    return;
  Frame[Y][X][0] = B;
  Frame[Y][X][1] = G;
  Frame[Y][X][2] = R;
}

void Display( void )
{
  int xs, ys;
  CMPL Z;

  glClearColor(0.30, 0.47, 0.8, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glRasterPos2d(-1, 1);
  glPixelZoom(Zoom, -Zoom);

  for (ys = 0; ys < FRAME_H; ys++)
    for (xs = 0; xs < FRAME_W; xs++)
    {
      Z.Re = xs * (double)(X1 - X0) / FRAME_W + X0;
      Z.Im = ys * (double)(Y1 - Y0) / FRAME_W + Y0;
      PutPixel(xs, ys, Mandelbrot(Z), Mandelbrot(Z), Mandelbrot(Z));
    }

  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}

void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
  else if (Key == 'f')
    glutFullScreen();
}

void main( int argc, char *argv[] )
{
  /* Initialization */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  /* Create window */
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(FRAME_W * Zoom + 100, FRAME_H * Zoom + 100);
  glutCreateWindow("9-2 one love");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glutMainLoop();
}
