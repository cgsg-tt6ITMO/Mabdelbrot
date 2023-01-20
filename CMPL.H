/**/

typedef unsigned char byte;

typedef struct
{
  double Re, Im;
} CMPL;

int Mandelbrot( CMPL Z );
CMPL CmplSet( double a, double b );
CMPL CmplAddCmpl( CMPL A, CMPL B );
CMPL CmplMulCmpl( CMPL A, CMPL B );
double CmplNorm( CMPL A );
