#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "read_input.h"
#include "param.h"

using namespace std;

void read_input(string input_file) {
  fstream ifile; 
  ifile.open(input_file, ios_base::in);

  string line;
  string str[10];

  size_t i=0;

  while(getline(ifile, line)) {
    stringstream iss;
    size_t pos = line.find("#");
    if(pos == 0) continue;
    if(pos != line.npos) {
      str[i] = line;
      if(i==0) {str[i].erase(pos); iss<<str[i]; iss>>hscale;}
      if(i==2) {str[i].erase(pos); iss<<str[i]; iss>>ewscale;}
    }
    i++;
  }
}
