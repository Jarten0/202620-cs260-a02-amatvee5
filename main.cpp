#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

#include "Address.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"
#include "ArrayList.h"

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
        .zip = std::stoi(items[6]),
    });
  }

  return entries;
}

int main()
{
  int size = 25000;
  cin >> size;

  ArrayList<Address> entries =
      read_entries_from_file("25000AddressesA.txt", size);

  ArrayList<Address> entries2 =
      read_entries_from_file("25000AddressesB.txt", size);

  entries.combine(entries2);

  cout << "Items in combined list: " << entries.length() << endl;
}
