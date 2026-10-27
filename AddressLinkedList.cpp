#include "AddressLinkedList.h"
#include "Address.h"

#include <iostream>
#include <stdexcept>
using namespace std;

AddressLinkedList::AddressLinkedList()
{
  head = nullptr;
  tail = nullptr;
}

AddressLinkedList::~AddressLinkedList()
{
  clear();
}

AddressLinkedList::AddressLinkedList(const AddressLinkedList& other)
{
  clear();

  AddressLLNode* current = other.head;
  while (current != nullptr) {
    insertEnd(current->data);
    current = current->next;
  }
}

AddressLinkedList AddressLinkedList::operator=(const AddressLinkedList& other)
{
  if (this == &other) {
    return *this;
  }

  clear();

  AddressLLNode* current = other.head;
  while (current != nullptr) {
    insertEnd(current->data);
    current = current->next;
  }

  return *this;
}

void AddressLinkedList::insertStart(Address value)
{
  head = new AddressLLNode{.next = head, .data = value};

  if (tail == nullptr) {
    tail = head;
  }
}

void AddressLinkedList::insertEnd(Address value)
{
  if (tail == nullptr) {
    head = new AddressLLNode{.next = nullptr, .data = value};
    tail = head;
    return;
  }

  tail->next = new AddressLLNode{.next = nullptr, .data = value};
  tail = tail->next;
}

void AddressLinkedList::clear()
{
  AddressLLNode* current = head;
  AddressLLNode* tmp = nullptr;
  while (current != nullptr) {
    tmp = current->next;
    delete current;
    current = tmp;
  }

  head = nullptr;
  tail = nullptr;
}

// start is inclusive, end is exclusive
void AddressLinkedList::printRange(int start, int end, AddressLLNode* current)
{
  if (start >= end || end <= 0) {
    return;
  }

  if (current == nullptr) {
    current = head;
  }

  if (start <= 0) {
    cout << to_string(current->data);
  }

  if (current->next == nullptr) {
    throw std::logic_error("printRange indexed out of bounds");
  }

  printRange(start - 1, end - 1, current->next);
}

void AddressLinkedList::combine(AddressLinkedList other)
{
  tail->next = other.head;
  tail = other.tail;
  other.head = nullptr;
  other.tail = nullptr;
}

AddressLinkedList
AddressLinkedList::extractAllMatches(const Address& itemToMatch)
{
  AddressLinkedList newList;

  AddressLLNode* current = head;

  while (current != nullptr) {
    if (current->data.state == itemToMatch.state) {
      newList.insertEnd(current->data);
    }

    current = current->next;
  }

  return newList;
}

int AddressLinkedList::count()
{
  int count = 0;

  AddressLLNode* current = head;

  while (current != nullptr) {
    current = current->next;
    count++;
  }

  return count;
}

// ooo i really liked writing this one
void AddressLinkedList::interleave(AddressLinkedList& other)
{
  if (head == nullptr) {
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    return;
  }

  AddressLLNode* iter1 = head;
  AddressLLNode* iter2 = other.head;
  AddressLLNode* tmp = nullptr;

  while (iter2 != nullptr) {
    tmp = iter1->next;
    iter1->next = iter2;
    iter2 = tmp;
    iter1 = iter1->next;
  }

  while (iter1->next != nullptr) {
    iter1 = iter1->next;
  }

  tail = iter1;

  other.head = nullptr;
  other.tail = nullptr;
}
