#include "metropolis.h"

double uniform(const double a, const double b) {
  return a + (b-a) * (double)rand() / (double)RAND_MAX;
}

void updateMetropolisHarmonic(double array[], const unsigned int size, const double eps, const double a) {
  for(unsigned int i = 0; i < size; ++i) {
    double oldx = array[i];
    double oldS = harmonicAction(i, array, size, a);
    array[i] = array[i] + uniform(-eps, eps);
    double dS = harmonicAction(i, array, size, a) - oldS;
    if(dS > 0 && exp(-dS) < uniform(0,1))
      array[i] = oldx;
  }
}

double harmonicAction(const unsigned int j, const double array[], const unsigned int size, const double a) {
  unsigned int jp1 = (j + 1) % size;
  unsigned int jm1 = (j - 1) % size;
  return a * array[j] * array[j]/2. + array[j] * (array[j] - array[jp1] - array[jm1])/a;
}
