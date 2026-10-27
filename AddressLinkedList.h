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
};

#endif
