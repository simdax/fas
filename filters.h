#ifndef _FAS_FILTERS_H_
#define _FAS_FILTERS_H_

  #include <math.h>

  double fast_tanh(const double x);

  extern double improved_moog(double input, double cutoff, double resonance, double drive, double *V, double *dV, double *tV, double sampleRate);
  extern double huovilainen_moog(double input, double cutoff_computed, double res_computed, double *delay, double *stage, double *stageTanh, int oversample);
  extern void huovilainen_compute(double cutoff, double resonance, double *cutoff_computed, double *res_computed, double sampleRate);

#endif
