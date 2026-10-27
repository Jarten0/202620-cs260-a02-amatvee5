#include <sstream>
#include <string>
using namespace std;

#include "Address.h"

string to_string(const Address& address)
{
  stringstream result;
  result << address.first << " " << address.last << endl;
  result << "\t" << address.city << ", " << address.state << " "
         << address.zipCode << endl;
  return result.str();

  // return address.address + " (City: " + address.city
  // + ", State: " + address.state + ")";
}
