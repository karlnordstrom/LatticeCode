#include "metropolis.h"
#include "observable.h"
#define size 20
#define Ncf 1000

int main(void) {

  const double a = 1./2;
  const double Ncor = 20;
  const double eps = 1.4;
  static double x[size];
  static double G[Ncf][size];

  for(unsigned int i = 0; i < size; ++i) {
    x[i] = 0.;
  }
  for(unsigned int i = 0; i < 5*Ncor; ++i) {
    updateMetropolisHarmonic(x, size, eps, a);
  }

  for(unsigned int it = 0; it < Ncf; ++it) {
    for(unsigned int i = 0; i < Ncor; ++i) {
      updateMetropolisHarmonic(x, size, eps, a);
    }
    for(unsigned int j = 0; j < size; ++j) {
      G[it][j] = computeGx1(x, size, j);
    }
  }
  double old_g = 0.;
  double avg_g = 0.;
  for(unsigned int i = 0; i < size; ++i) {
    old_g = avg_g;
    avg_g = 0;
    for(unsigned int it = 0; it < Ncf; ++it) {
      avg_g += G[it][i];
    }
    avg_g = avg_g / Ncf;
    printf("G(%d) = %f \n", i, avg_g);
    printf("Delta E(%d) = %f \n", i, log(0.000000001 + old_g/avg_g)/a);
  }

//  for(unsigned int i = 0; i < size_of_array; ++i) {
//    printf("x[%d]: %f \n", i, x[i]);
//  }

//  updateMetropolis(x, size_of_array, eps, a);

//  for(unsigned int i = 0; i < size_of_array; ++i) {
//    printf("x[%d]: %f \n", i, x[i]);
//  }



  return 0;
}
