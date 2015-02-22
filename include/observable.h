#include "metropolis.h"

/*

  Functions related to calculating operator values for
  path ensembles (generally the paths are generated by
  the functions themselves so that part is hidden from
  the user).

*/

// Calculate the operator values for G(t)=1/N \sum < x(j+t) x(j) >
void calculateGx1(double x[], double G[], const unsigned int size, const unsigned int Ncf, const unsigned int Ncor, const double eps, const double a);

// Calculate the operator values for G(t)=1/N \sum < x(j+t)^3 x(j)^3 >
void calculateGx3(double x[], double G[], const unsigned int size, const unsigned int Ncf, const unsigned int Ncor, const double eps, const double a);

// Calculate operator value for a particular ensemble for
// G(t)=1/N \sum < x(j+t) x(j) >
double _computeGx1(const double x[], const unsigned int size, const unsigned int n);

// Calculate operator value for a particular ensemble for
// G(t)=1/N \sum < x(j+t)^3 x(j)^3 >
double _computeGx3(const double x[], const unsigned int size, const unsigned int n);
