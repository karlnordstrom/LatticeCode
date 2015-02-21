#include "observable.h"

double computeGx1(const double x[], const unsigned int size, const unsigned int n) {
  double g = 0.;
  for(unsigned int i = 0; i < size; ++i) {
    g += x[i]*x[(i+n)%size];
  }
  return g/size;
}

