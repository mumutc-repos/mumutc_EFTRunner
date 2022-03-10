#ifndef SYS_SMEFT_H
#define SYS_SMEFT_H

#include <cmath>
#include "state_type.h"

struct sys_lq1 {
  double g, gp;
  double Gu33;
  double clq1_2, clq1_3;
  double clq3;
  double cqe_1, cqe_2, cqe_3;

  sys_lq1(double g_in, double gp_in, double Gu33_in, double clq1_2_in, double clq1_3_in, double clq3_in, double cqe_1_in, double cqe_2_in, double cqe_3_in): g(g_in), gp(gp_in), Gu33(Gu33_in), clq1_2(clq1_2_in), clq1_3(clq1_3_in), clq3(clq3_in), cqe_1(cqe_1_in), cqe_2(cqe_2_in), cqe_3(cqe_3_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (-gp*gp*x[0]+(2.0/3.0)*gp*gp*(x[0]+clq1_2+clq1_3)+9.0*g*g*clq3-2.0/3.0*gp*gp*(-cqe_1-cqe_2-cqe_3)+0.5*Gu33*Gu33*x[0])/(16.0*M_PI*M_PI);
  }
};//C^(1)_lq

struct sys_lq3 {
  double g, gp;
  double Gu33;
  double clq3_2, clq3_3;
  double clq1;
  
  sys_lq3(double g_in, double gp_in, double Gu33_in, double clq3_2_in, double clq3_3_in, double clq1_in): g(g_in), gp(gp_in), Gu33(Gu33_in), clq3_2(clq3_2_in), clq3_3(clq3_3_in), clq1(clq1_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (3.0*g*g*clq1-(6.0*g*g+gp*gp)*x[0]+2.0/3.0*g*g*(x[0]+clq3_2+clq3_3)+0.5*Gu33*Gu33*x[0])/(16.0*M_PI*M_PI);
 }
};//C^(3)_lq

struct sys_qe {
  double gp;
  double Gu33;
  double cqe_2, cqe_3;
  double clq1_1, clq1_2, clq1_3;

  sys_qe (double gp_in, double Gu33_in, double cqe_2_in, double cqe_3_in, double clq1_1_in, double clq1_2_in, double clq1_3_in): gp(gp_in), Gu33(Gu33_in), cqe_2(cqe_2_in), cqe_3(cqe_3_in), clq1_1(clq1_1_in), clq1_2(clq1_2_in), clq1_3(clq1_3_in) { }

  void operator() (const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = (4.0/3.0*gp*gp*(clq1_1+clq1_2+clq1_3+x[0]+cqe_2+cqe_3)+2.0*gp*gp*x[0]+0.5*Gu33*Gu33*x[0])/(16.0*M_PI*M_PI);
 }
};//C_qe

#endif
