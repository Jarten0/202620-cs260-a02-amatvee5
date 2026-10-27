#ifndef ADDRESSARRAYLIST_H
#define ADDRESSARRAYLIST_H

using namespace std;

#include "Address.h"
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
void ArrayList<Address>::combine(ArrayList<Address> other);

/**
 * Template specialization for ArrayList of Addresses
 *   This is defining an extractAllMatches that will ONLY work for an
 * ArrayList<Address> Because it is fully specified (no mystery type), it will
 * be implemented in the .cpp
 *
 * @brief Remove all items in which the state matches the itemToMatch.state from
 * the ArrayList and return them in a new ArrayList. All other items should
 * remain in their original order.
 * @param itemToMatch All items whose state matches this Address' .state this
 * value will be extracted
 * @return A new list containing the extracted items.
 *
 * NOTE: should extract items that have a matching .state, not just items that
 * are ==
 *
 * Sample usage:
 * Address searchAddress;
 * searchAddress.state = "OR";
 * ArrayList<Address> oregonList = masterList.extractAllMatches(searchAddress);
 */
template<>
ArrayList<Address>
ArrayList<Address>::extractAllMatches(const Address& itemToMatch);

#endif
