#include <cmath>
#include "state_type.h"

void sys_g( const state_type &x, state_type &dxdt, const double t);

void sys_gp( const state_type &x, state_type &dxdt, const double t);

void sys_gs( const state_type &x, state_type &dxdt, const double t);

void sys_gqcd( const state_type &x, state_type &dxdt, const double t);

void sys_eqed( const state_type &x, state_type &dxdt, const double t);

struct sys_Gu33 {
  double g, gp, gs;

  sys_Gu33(double g_in, double gp_in, double gs_in): g(g_in), gp(gp_in), gs(gs_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (9.0/4.0*g*g*x[0]-17.0/12.0*gp*gp*x[0]-8.0*gs*gs*x[0]+9.0/2.0*x[0]*x[0]*x[0])/(16.0*M_PI*M_PI);
  }
};
