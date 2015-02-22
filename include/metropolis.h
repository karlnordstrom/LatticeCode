#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

  Functions used to generate updating paths using the metropolis
  algorithm. These are mostly meant to be hidden from the user
  and used by the functions in observable.h.

*/

// Generate random number uniformly distributed between
// a and b (used the default C RNG which is pretty horrendous)
double uniform(const double a, const double b);

// Update the path stored in array[] using an action
// corresponding to the QHO
void updateMetropolisHarmonic(double array[], const unsigned int size, const double eps, const double a);

// Return the local action for the QHO
double harmonicAction(const unsigned int j, const double array[], const unsigned int size, const double a);
