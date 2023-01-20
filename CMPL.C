/**/

#include <math.h>

typedef struct
{
  double Re, Im;
} CMPL;

#define FRAME_W 100
#define FRAME_H 100

CMPL CmplSet( double a, double b )
{
  CMPL Z;

  Z.Re = a;
  Z.Im = b;
  return Z;
}

CMPL CmplAddCmpl( CMPL A, CMPL B )
{
  CMPL C;

  C.Re = A.Re + B.Re;
  C.Im = A.Im + B.Im;
  return C;
}

CMPL CmplMulCmpl( CMPL A, CMPL B )
{
  CMPL C;

  C.Re = A.Re * B.Re - A.Im * B.Im;
  C.Im = A.Re * B.Im + A.Im * B.Re;
  return C;
}

double CmplNorm( CMPL A )
{
  return sqrt(A.Re * A.Re + A.Im * A.Im);
}

int Mandelbrot( CMPL Z )
{
  int n = 0;
  CMPL Z0 = Z;

  while (n < 255 && CmplNorm(Z) < 2)
  {
    Z = CmplAddCmpl(CmplMulCmpl(Z, Z), Z0);
    n++;
  }

  return n;
}
