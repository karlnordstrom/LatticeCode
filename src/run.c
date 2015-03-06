#include "metropolis.h"
#include "operator.h"
#include "action.h"
#include "error.h"
#include "mt64.h"
#include "time.h"
#define size 100
#define Ncf 10000

int main(void) {

  const int seed = time(NULL);
  init_genrand64(seed);

  const double a = 1./10;
  const unsigned int Ncor = 50;
  const double eps = 1.4;
  // allocate memory to avoid overflowing the stack
  double *x = (double *) malloc (sizeof (double) * size);
  double *G = (double *) malloc (sizeof (double) * size * Ncf);

  // set up the action and operator we want to study
  Action action;
  action.action = &harmonicAction;
  action.parameters = (double[]){ 1. }; // the only parameter this action takes is omega

  Operator op;
  op.op = &Gx1;
  op.parameters = (double[]) {}; // no parameters

  // generate ensembles + calculate operator values
  // for these ensembles
  calculateOperator(x, G, size, Ncf, Ncor, eps, a, action, op);
  // average them out and calculate the first excitation level
  // by using log(G[j]/G[j+1])
  double old_g = 0.;
  double avg_g = 0.;
  double old_error = 0.;
  double g_error = 0.;
  for(unsigned int i = 0; i < size; ++i) {
    old_error = g_error;
    old_g = avg_g;
    avg_g = 0;
    for(unsigned int it = 0; it < Ncf; ++it) {
      avg_g += G[it*size+i];
    }
    avg_g = avg_g / Ncf;
    // Calculate the standard deviation on G using
    // the standard bootstrap procedure
    g_error = bootstrapError(G, Ncf, size, i, 100);
//    printf("G(%d) = %f +/- %f \n", i, avg_g, g_error);
    double delta_E = log(old_g/avg_g)/a;
    double E_error = (old_g/avg_g)*sqrt( (g_error/avg_g)*(g_error/avg_g) + (old_error/old_g)*(old_error/old_g) ) / delta_E;
    if (i != 0)
//      printf("Delta E(%d) = %f +/- %f \n", i, delta_E, E_error);
      printf("%d  %f  %f \n", i, delta_E, E_error);
  }

  free(x); free(G);

  return 0;
}
