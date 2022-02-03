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
    dxdt[0] = (-8.0/3.0*eqed*eqed*x[0]+4.0/3.0*(ldevlr_2+ldevlr_3+ledvll_1+ledvll_2+ledvll_3))/(16.0*M_PI*M_PI);
  }
};// L^{V,LR}_{de}
