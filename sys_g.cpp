#include <cmath>
#include "state_type.h"

void sys_g( const state_type &x, state_type &dxdt, const double t) {
  dxdt[0] = -19.0*x[0]*x[0]*x[0]/6.0/(16.0*M_PI*M_PI);
}

void sys_gp( const state_type &x, state_type &dxdt, const double t) {
  dxdt[0] = 41.0*x[0]*x[0]*x[0]/6.0/(16.0*M_PI*M_PI);
}

void sys_gs( const state_type &x, state_type &dxdt, const double t) {
  dxdt[0] = -7.0*x[0]*x[0]*x[0]/(16.0*M_PI*M_PI);
}

void sys_gqcd(const state_type &x, state_type &dxdt, const double t) {
  dxdt[0] = -23.0*x[0]*x[0]*x[0]/3.0/(16.0*M_PI*M_PI);
}

void sys_eqed(const state_type &x, state_type &dxdt, const double t) {
  dxdt[0] = 80.0*x[0]*x[0]*x[0]/9.0/(16.0*M_PI*M_PI);
}
