#ifndef ADDRESSARRAYLIST_H
#define ADDRESSARRAYLIST_H

using namespace std;

#include "Address.h"
#include "AddressArrayList.h"
#include "ArrayList.h"

// template<>
// class ArrayList<Address> {
// public:
// ArrayList(int reserve_size);

// ~ArrayList();

// Address& get(int index);

// void push(Address value);

// void combine(ArrayList<Address> other)
// {
// }
// };

template<>
void ArrayList<Address>::combine(ArrayList<Address> other)
{
  for (int i = 0; i < other.length(); i++) {
    push(other.get(i));
  }

  other._length = 0;
}

#endif
