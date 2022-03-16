#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "read_input.h"
#include "param.h"

using namespace std;

void read_sm_input(string input_file) {
  fstream ifile; 
  ifile.open(input_file, ios_base::in);

  string line;
  string str[10];

  size_t i=0;

  while(getline(ifile, line)) {
    if(!line.empty()) {
      stringstream iss;
      size_t pos = line.find("#");
      if(pos == 0) continue;
      if(pos != line.npos) {
        str[i] = line;
        if(i==0) {str[i].erase(pos); iss<<str[i]; iss>>hscale;}
        if(i==1) {str[i].erase(pos); iss<<str[i]; iss>>ewscale;}
        if(i==2) {str[i].erase(pos); iss<<str[i]; iss>>lscale;}
        if(i==3) {str[i].erase(pos); iss<<str[i]; iss>>gs_ew;}
        if(i==4) {str[i].erase(pos); iss<<str[i]; iss>>g_ew;}
        if(i==5) {str[i].erase(pos); iss<<str[i]; iss>>gp_ew;}
        if(i==6) {str[i].erase(pos); iss<<str[i]; iss>>gqcd_ew;}
        if(i==7) {str[i].erase(pos); iss<<str[i]; iss>>eqed_ew;}
        if(i==8) {str[i].erase(pos); iss<<str[i]; iss>>Gu33_ew;}
      }
      i++;
    }
  }
}

void read_smeft_input(string input_file) {
  fstream ifile; 
  ifile.open(input_file, ios_base::in);

  string line;
  string str[20];

  size_t i=0;

  while(getline(ifile, line)) {
    if(!line.empty()) {
      stringstream iss;
      size_t pos = line.find("#");
      if(pos == 0) continue;
      if(pos != line.npos) {
        str[i] = line;
        if(i==0) {str[i].erase(pos); iss<<str[i]; iss>>clq1_1_h;}
        if(i==1) {str[i].erase(pos); iss<<str[i]; iss>>clq1_2_h;}
        if(i==2) {str[i].erase(pos); iss<<str[i]; iss>>clq1_3_h;}
        if(i==3) {str[i].erase(pos); iss<<str[i]; iss>>clq3_1_h;}
        if(i==4) {str[i].erase(pos); iss<<str[i]; iss>>clq3_2_h;}
        if(i==5) {str[i].erase(pos); iss<<str[i]; iss>>clq3_3_h;}
        if(i==6) {str[i].erase(pos); iss<<str[i]; iss>>cqe_1_h;}
        if(i==7) {str[i].erase(pos); iss<<str[i]; iss>>cqe_2_h;}
        if(i==8) {str[i].erase(pos); iss<<str[i]; iss>>cqe_3_h;}
        if(i==9) {str[i].erase(pos); iss<<str[i]; iss>>ced_1_h;}
        if(i==10) {str[i].erase(pos); iss<<str[i]; iss>>ced_2_h;}
        if(i==11) {str[i].erase(pos); iss<<str[i]; iss>>ced_3_h;}
        if(i==12) {str[i].erase(pos); iss<<str[i]; iss>>cld_1_h;}
        if(i==13) {str[i].erase(pos); iss<<str[i]; iss>>cld_2_h;}
        if(i==14) {str[i].erase(pos); iss<<str[i]; iss>>cld_3_h;}
      }
      i++;
    }
  }
}

void read_left_input(string input_file) {
  fstream ifile; 
  ifile.open(input_file, ios_base::in);

  string line;
  string str[20];

  size_t i=0;

  while(getline(ifile, line)) {
    if(!line.empty()) {
      stringstream iss;
      size_t pos = line.find("#");
      if(pos == 0) continue;
      if(pos != line.npos) {
        str[i] = line;
        if(i==0) {str[i].erase(pos); iss<<str[i]; iss>>ledvll_1_l;}
        if(i==1) {str[i].erase(pos); iss<<str[i]; iss>>ledvll_2_l;}
        if(i==2) {str[i].erase(pos); iss<<str[i]; iss>>ledvll_3_l;}
        if(i==3) {str[i].erase(pos); iss<<str[i]; iss>>ldevlr_1_l;}
        if(i==4) {str[i].erase(pos); iss<<str[i]; iss>>ldevlr_2_l;}
        if(i==5) {str[i].erase(pos); iss<<str[i]; iss>>ldevlr_3_l;}
        if(i==6) {str[i].erase(pos); iss<<str[i]; iss>>ledvlr_1_l;}
        if(i==7) {str[i].erase(pos); iss<<str[i]; iss>>ledvlr_2_l;}
        if(i==8) {str[i].erase(pos); iss<<str[i]; iss>>ledvlr_3_l;}
        if(i==9) {str[i].erase(pos); iss<<str[i]; iss>>ledvrr_1_l;}
        if(i==10) {str[i].erase(pos); iss<<str[i]; iss>>ledvrr_2_l;}
        if(i==11) {str[i].erase(pos); iss<<str[i]; iss>>ledvrr_3_l;}
      }
      i++;
    }
  } 
}
