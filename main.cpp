#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

#include "Address.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"
#include "ArrayList.h"

class AddressFactory {
  std::ifstream infile;
  int entriesLeft = 0;

public:
  AddressFactory(string inputFile, int maxEntries = 25000)
  {
    entriesLeft = maxEntries;
    infile.open(inputFile);
  }

  Address getNextAddress()
  {
    if (entriesLeft-- <= 0) {
      throw std::logic_error("read too many addresses");
    }

    string line;

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

    return (Address{
        .last = items[0],
        .first = items[1],
        .address = items[2],
        .city = items[3],
        .county = items[4],
        .state = items[5],
        .zipCode = std::stoi(items[6]),
    });
  }
};

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

  AddressFactory factory1("25000AddressesA.txt", size);
  AddressFactory factory2("25000AddressesB.txt", size);

  AddressLinkedList linkListA;
  AddressLinkedList linkListB;

  for (int i = 0; i < size / 2; i++) {
    linkListA.insertEnd(factory1.getNextAddress());
    linkListB.insertEnd(factory2.getNextAddress());
  }

  linkListA.printRange(2, 5);
  linkListB.printRange(2, 5);
}
