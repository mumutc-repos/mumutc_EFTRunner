#include <iostream>
#include <fstream>
#include <cmath>

#include <boost/numeric/odeint.hpp>

#include "state_type.h"
#include "sys_g.h"
#include "sys_SMEFT.h"

using namespace std;
using namespace boost::numeric::odeint;

const int STEP = 100;

int main(int argc, char **argv) {

fstream ofile;
ofile.open("output.txt", ios_base::out);

double hscale = 1000.0;
double ewscale = 91.1876;
double lscale = 5.0;

double log_hscale, log_ewscale, log_lscale;
double dth, dtl;

//EW input
double g_ew, gp_ew, gs_ew;
double gqcd_ew, eqed_ew;
double sw_ew;

double clq1_1_ew, clq1_2_ew, clq1_3_ew;
double clq3_1_ew, clq3_2_ew, clq3_3_ew;
double cqe_1_ew, cqe_2_ew, cqe_3_ew;

//high scale input
double g_h, gp_h, gs_h;

double clq1_1_h, clq1_2_h, clq1_3_h;
double clq3_1_h, clq3_2_h, clq3_3_h;
double cqe_1_h, cqe_2_h, cqe_3_h;

//system functions
state_type g_run, gp_run, gs_run;
state_type gqcd_run, eqed_run;

state_type clq1_1_run, clq1_2_run, clq1_3_run;
state_type clq3_1_run, clq3_2_run, clq3_3_run;
state_type cqe_1_run, cqe_2_run, cqe_3_run;

g_ew = 0.6515;
gp_ew = 0.3576;
gs_ew = 1.220;
gqcd_ew = 1.220;
sw_ew = sqrt(gp_ew*gp_ew/(gp_ew*gp_ew+g_ew*g_ew));
eqed_ew = g_ew*sw_ew;

log_hscale = log(hscale);
log_ewscale = log(ewscale);
log_lscale = log(lscale);

dth = (log_hscale-log_ewscale)/STEP;
cout<<dth<<endl;

clq1_1_h = 1.0e-6;
clq1_2_h = 0.0e-6;
clq1_3_h = 0.0e-6;

clq3_1_h = 1.0e-6;
clq3_2_h = 0.0e-6;
clq3_3_h = 0.0e-6;

cqe_1_h = 0.0e-6;
cqe_2_h = 0.0e-6;
cqe_3_h = 0.0e-6;

g_run[0] = g_ew;
gp_run[0] = gp_ew;
gs_run[0] = gs_ew;

for(size_t i=0; i<STEP; ++i) {
  runge_kutta4< state_type > rk;
  rk.do_step(sys_g, g_run, log_ewscale, dth);
  rk.do_step(sys_gp, gp_run, log_ewscale, dth);
  rk.do_step(sys_gs, gs_run, log_ewscale, dth);
  log_ewscale = log_ewscale + dth;
} 

clq1_1_run[0] = clq1_1_h;
clq1_2_run[0] = clq1_2_h;
clq1_3_run[0] = clq1_3_h;

clq3_1_run[0] = clq3_1_h;
clq3_2_run[0] = clq3_2_h;
clq3_3_run[0] = clq3_3_h;

cqe_1_run[0] = cqe_1_h;
cqe_2_run[0] = cqe_2_h;
cqe_3_run[0] = cqe_3_h;

cout<<"high scale: "<<exp(log_ewscale)<<endl;
cout<<"g="<<g_run[0]<<endl;
cout<<"gp="<<gp_run[0]<<endl;
cout<<"gs="<<gs_run[0]<<endl;
cout<<"clq1_1="<<clq1_1_run[0]<<endl;
cout<<"clq1_2="<<clq1_2_run[0]<<endl;
cout<<"clq1_3="<<clq1_3_run[0]<<endl;
cout<<"clq3_1="<<clq3_1_run[0]<<endl;
cout<<"clq3_2="<<clq3_2_run[0]<<endl;
cout<<"clq3_3="<<clq3_3_run[0]<<endl;
cout<<"cqe_1="<<cqe_1_run[0]<<endl;
cout<<"cqe_2="<<cqe_2_run[0]<<endl;
cout<<"cqe_3="<<cqe_3_run[0]<<endl;

for(size_t i=0; i<STEP; ++i) {
  sys_lq1 sf_lq1_1(g_run[0], gp_run[0], clq1_2_run[0], clq1_3_run[0], clq3_1_run[0], cqe_1_run[0], cqe_2_run[0], cqe_3_run[0]);
  sys_lq1 sf_lq1_2(g_run[0], gp_run[0], clq1_3_run[0], clq1_1_run[0], clq3_2_run[0], cqe_1_run[0], cqe_2_run[0], cqe_3_run[0]);
  sys_lq1 sf_lq1_3(g_run[0], gp_run[0], clq1_1_run[0], clq1_2_run[0], clq3_3_run[0], cqe_1_run[0], cqe_2_run[0], cqe_3_run[0]);
  sys_lq3 sf_lq3_1(g_run[0], gp_run[0], clq3_2_run[0], clq3_3_run[0], clq1_1_run[0]);
  sys_lq3 sf_lq3_2(g_run[0], gp_run[0], clq3_3_run[0], clq3_1_run[0], clq1_2_run[0]);
  sys_lq3 sf_lq3_3(g_run[0], gp_run[0], clq3_1_run[0], clq3_2_run[0], clq1_3_run[0]);
  sys_qe sf_qe_1(gp_run[0], cqe_2_run[0], cqe_3_run[0], clq1_1_run[0], clq1_2_run[0], clq1_3_run[0]);
  sys_qe sf_qe_2(gp_run[0], cqe_3_run[0], cqe_1_run[0], clq1_1_run[0], clq1_2_run[0], clq1_3_run[0]);
  sys_qe sf_qe_3(gp_run[0], cqe_1_run[0], cqe_2_run[0], clq1_1_run[0], clq1_2_run[0], clq1_3_run[0]);
  runge_kutta4< state_type > rk;
  rk.do_step(sf_lq1_1, clq1_1_run, log_ewscale, -dth);
  rk.do_step(sf_lq1_2, clq1_2_run, log_ewscale, -dth);
  rk.do_step(sf_lq1_3, clq1_3_run, log_ewscale, -dth);
  rk.do_step(sf_lq3_1, clq3_1_run, log_ewscale, -dth);
  rk.do_step(sf_lq3_2, clq3_2_run, log_ewscale, -dth);
  rk.do_step(sf_lq3_3, clq3_3_run, log_ewscale, -dth);
  rk.do_step(sf_qe_1, cqe_1_run, log_ewscale, -dth);
  rk.do_step(sf_qe_2, cqe_2_run, log_ewscale, -dth);
  rk.do_step(sf_qe_3, cqe_3_run, log_ewscale, -dth);
  rk.do_step(sys_g, g_run, log_ewscale, -dth);
  rk.do_step(sys_gp, gp_run, log_ewscale, -dth);
  rk.do_step(sys_gs, gs_run, log_ewscale, -dth);
  log_ewscale = log_ewscale - dth;
  ofile<<exp(log_ewscale)<<" "<<cqe_1_run[0]<<endl; 
}

cout<<"EW scale: "<<ewscale<<endl;
cout<<"g="<<g_run[0]<<endl;
cout<<"gp="<<gp_run[0]<<endl;
cout<<"gs="<<gs_run[0]<<endl;
cout<<"clq1_1="<<clq1_1_run[0]<<endl;
cout<<"clq1_2="<<clq1_2_run[0]<<endl;
cout<<"clq1_3="<<clq1_3_run[0]<<endl;
cout<<"clq3_1="<<clq3_1_run[0]<<endl;
cout<<"clq3_2="<<clq3_2_run[0]<<endl;
cout<<"clq3_3="<<clq3_3_run[0]<<endl;
cout<<"cqe_1="<<cqe_1_run[0]<<endl;
cout<<"cqe_2="<<cqe_2_run[0]<<endl;
cout<<"cqe_3="<<cqe_3_run[0]<<endl;

return 0;
}//end of main
