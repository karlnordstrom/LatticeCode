#ifndef METROPOLIS_H
#define METROPOLIS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mt64.h"

/*

  Functions used to generate updating paths using the metropolis
  algorithm. These are mostly meant to be hidden from the user
  and used by the functions in observable.h.

*/

// Generate random number uniformly distributed between
// a and b using a 64 bit Mersenne Twister
double uniform(const double a, const double b);

// Update the path stored in array[] using an action
// corresponding to the QHO
void updateMetropolis(double array[], const unsigned int size, const double eps, const double a, double (*actionPtr)(const unsigned int, const double*, const unsigned int, const double));

// Return the local action for the QHO
double harmonicAction(const unsigned int j, const double array[], const unsigned int size, const double a);
// As above but using higher order finite difference
double harmonicActionImproved(const unsigned int j, const double array[], const unsigned int size, const double a);

#endif
