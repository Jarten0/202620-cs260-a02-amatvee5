#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

struct Address {
  string last;
  string first;
  string address;
  string city;
  string county;
  string state;
  int zip;
};

#endif
