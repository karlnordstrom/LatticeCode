#include "metropolis.h"

double uniform(const double a, const double b) {
  return a + (b-a) * genrand64_real1();
}

__device__ double generate( int ind )
{
    double RANDOM = curand_uniform();
    return RANDOM;
}

__global__ void updateMetropolis(double array[], const double eps, const double a, const double omega) {
  int idx = threadIdx.x + (blockIdx.x * blockDim.x);
  double oldx = array[idx];
  double oldS = harmonicActionImproved(idx, array, size, a, omega);
  array[i] = array[idx] + uniform(-eps, eps);
  double dS = harmonicActionImproved(idx, array, size, a, currentAction.parameters) - oldS;
  if(dS > 0 && exp(-dS) < uniform(0,1))
    array[i] = oldx;
}

__device__ double harmonicAction(const unsigned int j, const double array[], const unsigned int size, const double a, const double omega) {
  const unsigned int jp1 = (size + j + 1) % size;
  const unsigned int jm1 = (size + j - 1) % size;
  return a * omega*omega * array[j] * array[j]/2. + array[j] * (array[j] - array[jp1] - array[jm1])/a;
}

__device__ double harmonicActionImproved(const unsigned int j, const double array[], const unsigned int size, const double a, const double omega) {
  const unsigned int jp1 = (size + j + 1) % size;
  const unsigned int jp2 = (size + j + 2) % size;
  const unsigned int jm1 = (size + j - 1) % size;
  const unsigned int jm2 = (size + j - 2) % size;
  return a * omega*omega * array[j] * array[j]/2. + array[j] * ( (1./12)*(array[jm2] + array[jp2]) - (8./6)*(array[jm1] + array[jp1]) + (5./4)*array[j] )/a;
}
