#ifndef SYS_LEFT_H
#define SYS_LEFT_H

#include <cmath>
#include "state_type.h"

struct sys_edvll {
  double eqed;
  double ledvll_2, ledvll_3;
  double ldevlr_1, ldevlr_2, ldevlr_3;

  sys_edvll(double eqed_in, double ledvll_2_in, double ledvll_3_in, double ldevlr_1_in, double ldevlr_2_in, double ldevlr_3_in): eqed(eqed_in), ledvll_2(ledvll_2_in), ledvll_3(ledvll_3_in), ldevlr_1(ldevlr_1_in), ldevlr_2(ldevlr_2_in), ldevlr_3(ldevlr_3_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (16.0/3.0*eqed*eqed*x[0]+4.0/3.0*eqed*eqed*(ledvll_2+ledvll_3+ldevlr_1+ldevlr_2+ldevlr_3))/(16.0*M_PI*M_PI);
  }
};// L^{V,LL}_{ed}

struct sys_devlr {
  double eqed;
  double ldevlr_2, ldevlr_3;
  double ledvll_1, ledvll_2, ledvll_3;

  sys_devlr(double eqed_in, double ldevlr_2_in, double ldevlr_3_in, double ledvll_1_in, double ledvll_2_in, double ledvll_3_in): eqed(eqed_in), ldevlr_2(ldevlr_2_in), ldevlr_3(ldevlr_3_in), ledvll_1(ledvll_1_in), ledvll_2(ledvll_2_in), ledvll_3(ledvll_3_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (-8.0/3.0*eqed*eqed*x[0]+4.0/3.0*eqed*eqed*(ldevlr_2+ldevlr_3+ledvll_1+ledvll_2+ledvll_3))/(16.0*M_PI*M_PI);
  }
};// L^{V,LR}_{de}

struct sys_edvlr {
  double eqed; 
  double ledvlr_2, ledvlr_3;
  double ledvrr_1, ledvrr_2, ledvrr_3;

  sys_edvlr(double eqed_in, double ledvlr_2_in, double ledvlr_3_in, double ledvrr_1_in, double ledvrr_2_in, double ledvrr_3_in): eqed(eqed_in), ledvlr_2(ledvlr_2_in), ledvlr_3(ledvlr_3_in), ledvrr_1(ledvrr_1_in), ledvrr_2(ledvrr_2_in), ledvrr_3(ledvrr_3_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (-8.0/3.0*eqed*eqed*x[0]+4.0/3.0*eqed*eqed*(ledvlr_2+ledvlr_3+ledvrr_1+ledvrr_2+ledvrr_3))/(16.0*M_PI*M_PI);
  }
};// L^{V,LR}_{ed}

struct sys_edvrr {
  double eqed;
  double ledvrr_2, ledvrr_3;
  double ledvlr_1, ledvlr_2, ledvlr_3;

  sys_edvrr(double eqed_in, double ledvrr_2_in, double ledvrr_3_in, double ledvlr_1_in, double ledvlr_2_in, double ledvlr_3_in): eqed(eqed_in), ledvrr_2(ledvrr_2_in), ledvrr_3(ledvrr_3_in), ledvlr_1(ledvlr_1_in), ledvlr_2(ledvlr_2_in), ledvlr_3(ledvlr_3_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (16.0/3.0*eqed*eqed*x[0]+4.0/3.0*eqed*eqed*(ledvrr_2+ledvrr_3+ledvlr_1+ledvlr_2+ledvlr_3))/(16.0*M_PI*M_PI);
  }
};// L^{V,RR}_{ed}

#endif
