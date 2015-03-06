#include "metropolis.h"
#include "observable.h"
#include "error.h"
#include "mt64.h"
#include "time.h"
#define size 100
#define Ncf 10000
#define rebin 5

int main(void) {

  const int seed = time(NULL);
  init_genrand64(seed);

  const double a = 1./10;
  const unsigned int Ncor = 50;
  const double eps = 1.4;
  // allocate memory to avoid overflowing the stack
  double *x = (double *) malloc (sizeof (double) * size);
  double *G = (double *) malloc (sizeof (double) * size * Ncf);

  // generate ensembles + calculate operator values
  // for these ensembles
  calculateGx1Improved(x, G, size, Ncf, Ncor, eps, a);
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
  // rebin the operator values and redo the calculation
  double *Gbinned = (double *) malloc (sizeof (double) * size * Ncf / rebin);
//  rebinArray(G, Gbinned, size, Ncf, rebin);
//  old_g = 0.;
//  avg_g = 0.;
//  old_error = 0.;
//  g_error = 0.;
//  for(unsigned int i = 0; i < size; ++i) {
//    old_g = avg_g;
//    avg_g = 0;
//    for(unsigned int it = 0; it < Ncf/rebin; ++it) {
//      avg_g += Gbinned[it*size+i];
//    }
//    avg_g = avg_g / (Ncf/rebin);
//    double g_error = bootstrapError(Gbinned, Ncf/rebin, size, i, 1000);
//    double delta_E = log(old_g/avg_g)/a;
//    double E_error = (old_g/avg_g)*sqrt( (g_error/avg_g)*(g_error/avg_g) + (old_error/old_g)*(old_error/old_g) ) / delta_E;
////    printf("G(%d) = %f +/- %f \n", i, avg_g, g_error);
//    if (i != 0)
//      printf("Delta E(%d) = %f +/- %f \n", i, delta_E, E_error);
//  }


  free(x); free(G); free(Gbinned);

  return 0;
}
