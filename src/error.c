#include "error.h"

double bootstrapError(const double G[], const unsigned int Ncf, const unsigned int size, const unsigned int n, const unsigned int Nerror) {
  double *_result = (double *) malloc (sizeof (double) * Nerror);
  for(unsigned int j = 0; j < Nerror; ++j) {
    _result[j] = 0.;
    for(unsigned int it = 0; it < Ncf; ++it) {
      unsigned int i = (unsigned int) round(uniform(0, Ncf));
      _result[j] += G[i*size+n] / Ncf;
    }
  }
  double error = 0.;
  double average = 0.;
  for(unsigned int j = 0; j < Nerror; ++j) {
    average += _result[j]/Nerror;
  }
  for(unsigned int j = 0; j < Nerror; ++j) {
    error += (_result[j] - average) * (_result[j] - average) / Nerror;
  }
  free(_result);
  return sqrt(error);
}

void rebinArray(const double G[], double newG[], const unsigned int size, const unsigned int Ncf, const unsigned int bins) {
  for(unsigned int x = 0; x < size; ++x) {
    for(unsigned int i = 0; i < (Ncf/bins); ++i) {
      double tmp = 0.;
      for(unsigned int j = 0; j < bins; ++j) {
        tmp += G[(bins*i+j)*size+x];
      }
      newG[i*size+x] = tmp/bins;
    }
  }
}
