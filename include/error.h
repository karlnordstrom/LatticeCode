#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "metropolis.h"

/*

  The functions defined here are used for estimating errors.

*/

// Estimate the error on the operator expectation value using
// the standard bootstrap algorithm.
double bootstrapError(const double G[], const unsigned int Ncf, const unsigned int size, const unsigned int n, const unsigned int Nerror);

// Rebin the operator values (can be used for estimating how
// large a role correlations between paths plays in the error)
void rebinArray(const double G[], double newG[], const unsigned int size, const unsigned int Ncf, const unsigned int bins);

