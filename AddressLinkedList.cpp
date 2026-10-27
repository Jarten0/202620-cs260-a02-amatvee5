#include "AddressLinkedList.h"
#include "Address.h"

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
