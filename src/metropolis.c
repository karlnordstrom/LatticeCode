#include "metropolis.h"

double uniform(const double a, const double b) {
  return a + (b-a) * genrand64_real1();
}

__global__ void updateMetropolis(double array[], const unsigned int size, const double eps, const double a) {
  int idx = threadIdx.x + (blockIdx.x * blockDim.x);
  double oldx = array[i];
  double oldS = (*currentAction.action)(i, array, size, a, currentAction.parameters);
  array[i] = array[i] + uniform(-eps, eps);
  double dS = harmonicActionImproved(i, array, size, a, currentAction.parameters) - oldS;
  if(dS > 0 && exp(-dS) < uniform(0,1))
    array[i] = oldx;
}

double harmonicAction(const unsigned int j, const double array[], const unsigned int size, const double a, const double *parameters) {
  const double omega = parameters[0];
  const unsigned int jp1 = (size + j + 1) % size;
  const unsigned int jm1 = (size + j - 1) % size;
  return a * omega*omega * array[j] * array[j]/2. + array[j] * (array[j] - array[jp1] - array[jm1])/a;
}

double harmonicActionImproved(const unsigned int j, const double array[], const unsigned int size, const double a, const double *parameters) {
  const double omega = parameters[0];
  const unsigned int jp1 = (size + j + 1) % size;
  const unsigned int jp2 = (size + j + 2) % size;
  const unsigned int jm1 = (size + j - 1) % size;
  const unsigned int jm2 = (size + j - 2) % size;
  return a * omega*omega * array[j] * array[j]/2. + array[j] * ( (1./12)*(array[jm2] + array[jp2]) - (8./6)*(array[jm1] + array[jp1]) + (5./4)*array[j] )/a;
}
