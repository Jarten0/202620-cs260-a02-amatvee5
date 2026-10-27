#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

#include "Address.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"
#include "ArrayList.h"

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

ArrayList<Address> read_entries_from_file(string filePath, int maxEntries)
{
  std::ifstream infile;
  infile.open(filePath);

  ArrayList<Address> entries(maxEntries);

  for (int i = 0; i < maxEntries; i++) {
    string line;
    // infile >> line;

    getline(infile, line);

    int sep = 7;
    string items[7];

    int i2 = 0;
    for (int i = 0; i < line.length() && i2 < sep; i++) {
      if (line[i] == ',') {
        i2++;
        continue;
      }

      items[i2] += line[i];
    }

    entries.push(Address{
        .last = items[0],
        .first = items[1],
        .address = items[2],
        .city = items[3],
        .county = items[4],
        .state = items[5],
        .zipCode = std::stoi(items[6]),
    });
  }

  return entries;
}

int main()
{
  int size = 25000;
  cin >> size;

  cout << " -------------------- Part 1 -------------------- " << endl;

  ArrayList<Address> aListA =
      read_entries_from_file("25000AddressesA.txt", size);

  ArrayList<Address> aListB =
      read_entries_from_file("25000AddressesB.txt", size);

  aListA.combine(aListB);

  cout << "Item count of combined list: " << aListA.length() << endl;

  cout << to_string(aListA.get(aListA.length() / 2 - 2)) << endl;
  cout << to_string(aListA.get(aListA.length() / 2 + 1)) << endl;

  cout << " -------------------- Part 2 -------------------- " << endl;

  ArrayList<Address> aListC = aListA.extractAllMatches(Address{.state = "OR"});

  cout << "Item count of initial list: " << aListA.length() << endl;
  cout << "Item count of resulting list: " << aListC.length() << endl;

  cout << to_string(aListC.get(0)) << endl;
  cout << to_string(aListC.get(1)) << endl;

  cout << " -------------------- Part 3 -------------------- " << endl;
}
