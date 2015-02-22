#include "observable.h"

void calculateGx1(double x[], double G[], const unsigned int size, const unsigned int Ncf, const unsigned int Ncor, const double eps, const double a) {
  // initialise so that x[j] = 0 for all j
  for(unsigned int i = 0; i < size; ++i) {
    x[i] = 0.;
  }
  // thermalise x
  for(unsigned int i = 0; i < 5*Ncor; ++i) {
    updateMetropolisHarmonic(x, size, eps, a);
  }
  // compute G for Ncf different x configurations
  for(unsigned int it = 0; it < Ncf; ++it) {
    for(unsigned int i = 0; i < Ncor; ++i) {
      updateMetropolisHarmonic(x, size, eps, a);
    }
    for(unsigned int j = 0; j < size; ++j) {
      G[it*size+j] = _computeGx1(x, size, j);
    }
  }
}

void calculateGx3(double x[], double G[], const unsigned int size, const unsigned int Ncf, const unsigned int Ncor, const double eps, const double a) {
  // initialise so that x[j] = 0 for all j
  for(unsigned int i = 0; i < size; ++i) {
    x[i] = 0.;
  }
  // thermalise x
  for(unsigned int i = 0; i < 5*Ncor; ++i) {
    updateMetropolisHarmonic(x, size, eps, a);
  }
  // compute G for Ncf different x configurations
  for(unsigned int it = 0; it < Ncf; ++it) {
    for(unsigned int i = 0; i < Ncor; ++i) {
      updateMetropolisHarmonic(x, size, eps, a);
    }
    for(unsigned int j = 0; j < size; ++j) {
      G[it*size+j] = _computeGx3(x, size, j);
    }
  }
}

double _computeGx1(const double x[], const unsigned int size, const unsigned int n) {
  double g = 0.;
  for(unsigned int i = 0; i < size; ++i) {
    g += x[i]*x[(i+n)%size];
  }
  return g/size;
}

double _computeGx3(const double x[], const unsigned int size, const unsigned int n) {
  double g = 0.;
  for(unsigned int i = 0; i < size; ++i) {
    g += x[i]*x[i]*x[i]*x[(i+n)%size]*x[(i+n)%size]*x[(i+n)%size];
  }
  return g/size;
}
