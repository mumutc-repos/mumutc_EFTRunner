#ifndef PARAM_H
#define PARAM_H

//Physical scales
extern double hscale;                              //UV scale for new physics
extern double ewscale;                             //EW scale for matching
extern double lscale;                              //Low scale for B physics

//SM parameters at EW scale
extern double g_ew, gp_ew, gs_ew;                  //Gauge couplings for SM
extern double gqcd_ew, eqed_ew;                    //Gauge couplings for QCD+QED
extern double Gu33_ew;                             //(3,3) element of Yukawa mass matrix

//SMEFT parameters at HIGH scale
extern double clq1_1_h, clq1_2_h, clq1_3_h;        //Clq1
extern double clq3_1_h, clq3_2_h, clq3_3_h;        //Clq3
extern double cqe_1_h, cqe_2_h, cqe_3_h;           //Cqe
extern double ced_1_h, ced_2_h, ced_3_h;           //Ced
extern double cld_1_h, cld_2_h, cld_3_h;           //Cld

//LEFT parameters at LOW scale
extern double ledvll_1_l, ledvll_2_l, ledvll_3_l;  //LedVLL
extern double ldevlr_1_l, ldevlr_2_l, ldevlr_3_l;  //LdeVLR
extern double ledvlr_1_l, ledvlr_2_l, ledvlr_3_l;  //LedVLR
extern double ledvrr_1_l, ledvrr_2_l, ledvrr_3_l;  //LdeVRR

#endif
