#include "metropolis.h"

double uniform(const double a, const double b) {
  //return a + (b-a) * (double)rand() / (double)RAND_MAX;
  return a + (b-a) * genrand64_real1();
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

void updateMetropolisHarmonicImproved(double array[], const unsigned int size, const double eps, const double a) {
  for(unsigned int i = 0; i < size; ++i) {
    double oldx = array[i];
    double oldS = harmonicActionImproved(i, array, size, a);
    array[i] = array[i] + uniform(-eps, eps);
    double dS = harmonicActionImproved(i, array, size, a) - oldS;
    if(dS > 0 && exp(-dS) < uniform(0,1))
      array[i] = oldx;
  }
}

double harmonicAction(const unsigned int j, const double array[], const unsigned int size, const double a) {
  const unsigned int jp1 = (size + j + 1) % size;
  const unsigned int jm1 = (size + j - 1) % size;
  return a * array[j] * array[j]/2. + array[j] * (array[j] - array[jp1] - array[jm1])/a;
}

double harmonicActionImproved(const unsigned int j, const double array[], const unsigned int size, const double a) {
  const unsigned int jp1 = (size + j + 1) % size;
  const unsigned int jp2 = (size + j + 2) % size;
  const unsigned int jm1 = (size + j - 1) % size;
  const unsigned int jm2 = (size + j - 2) % size;
  return a * 1 * array[j] * array[j]/2. + array[j] * ( (1./12)*(array[jm2] + array[jp2]) - (8./6)*(array[jm1] + array[jp1]) + (5./4)*array[j] )/a;
}
