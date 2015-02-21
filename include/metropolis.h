#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double uniform(const double a, const double b);

void updateMetropolisHarmonic(double array[], const unsigned int size, const double eps, const double a);

double harmonicAction(const unsigned int j, const double array[], const unsigned int size, const double a);
