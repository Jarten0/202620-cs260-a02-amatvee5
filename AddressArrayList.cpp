
#include "AddressArrayList.h"
#include "Address.h"
#include "ArrayList.h"

template<>
void ArrayList<Address>::combine(ArrayList<Address> other)
{
  for (int i = 0; i < other.length(); i++) {
    push(other.get(i));
  }

  other._length = 0;
}

template<>
ArrayList<Address>
ArrayList<Address>::extractAllMatches(const Address& itemToMatch)
{
  ArrayList<Address> newList(2);

  for (int i = 0; i < length(); i++) {
    if (get(i).state == itemToMatch.state) {
      newList.push(get(i));
    }
  }
}
