#include "operator.h"

void calculateOperator(double x[], double G[], const unsigned int size, const unsigned int Ncf, const unsigned int Ncor, const double eps, const double a, Action currentAction, Operator currentOperator) {
  // initialise so that x[j] = 0 for all j
  for(unsigned int i = 0; i < size; ++i) {
    x[i] = 0.;
  }
  // thermalise x
  for(unsigned int i = 0; i < 5*Ncor; ++i) {
    updateMetropolis(x, size, eps, a, currentAction);
  }
  // compute G for Ncf different x configurations
  for(unsigned int it = 0; it < Ncf; ++it) {
    for(unsigned int i = 0; i < Ncor; ++i) {
      updateMetropolis(x, size, eps, a, currentAction);
    }
    for(unsigned int j = 0; j < size; ++j) {
      G[it*size+j] = (*currentOperator.op)(x, size, j, currentOperator.parameters);
    }
  }
}

double Gx1(const double x[], const unsigned int size, const unsigned int n, const double *params) {
  double g = 0.;
  for(unsigned int i = 0; i < size; ++i) {
    g += x[i]*x[(size+i+n)%size];
  }
  return g/size;
}

double Gx3(const double x[], const unsigned int size, const unsigned int n, const double *params) {
  double g = 0.;
  for(unsigned int i = 0; i < size; ++i) {
    g += x[i]*x[i]*x[i]*x[(size+i+n)%size]*x[(size+i+n)%size]*x[(size+i+n)%size];
  }
  return g/size;
}
