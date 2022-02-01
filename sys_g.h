#include "state_type.h"

void sys_g( const state_type &x, state_type &dxdt, const double t);

void sys_gp( const state_type &x, state_type &dxdt, const double t);

void sys_gs( const state_type &x, state_type &dxdt, const double t);

void sys_gqcd( const state_type &x, state_type &dxdt, const double t);

void sys_eqed( const state_type &x, state_type &dxdt, const double t);
