#ifndef ADDRESSLINKEDLIST_H
#define ADDRESSLINKEDLIST_H

using namespace std;
#include "Address.h"

struct AddressLLNode {
  AddressLLNode* next = nullptr;
  Address data;
};

class AddressLinkedList {
public:
  AddressLLNode* head = nullptr;
  AddressLLNode* tail = nullptr;

  AddressLinkedList();

  ~AddressLinkedList();

  AddressLinkedList(const AddressLinkedList& other);

  AddressLinkedList operator=(const AddressLinkedList& other);

  void insertStart(Address value);

  void insertEnd(Address value);

  void clear();

  void printRange(int start, int end, AddressLLNode* = nullptr);

  void combine(AddressLinkedList other);

  int count();

  AddressLinkedList extractAllMatches(const Address& itemToMatch);

  /**
   * @brief interleaves the other list into this one
   * @return other List to combine - should end up emptied
   *
   * Assuming this list looks like {a, b, c, d} and other is {w, x, y, z}
   *  this list should end as {a, w, b, x, c, y, d, z} and other as {}
   */
  void interleave(AddressLinkedList& other);
};

#endif
