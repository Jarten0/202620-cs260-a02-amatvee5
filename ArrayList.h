#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <exception>
#include <stdexcept>
using namespace std;

template<typename T>
class ArrayList {
private:
  unsigned int _length = 0;
  unsigned int capacity = 0;
  T* data = nullptr;

  void resize();

public:
  ArrayList(int reserve_size);

  ~ArrayList();

  ArrayList(const ArrayList<T>& other);

  ArrayList operator=(const ArrayList<T>& other);

  T& get(int index);

  int length() const;

  void push(T value);

  void combine(ArrayList<T> other);

  ArrayList<T> extractAllMatches(const T& itemToMatch);
};

template<typename T>
ArrayList<T>::ArrayList(int reserve_size)
{
  _length = 0;
  capacity = reserve_size;
  data = new T[capacity];
}

template<typename T>
ArrayList<T>::~ArrayList()
{
  if (data) {
    delete[] data;
  }
}

template<typename T>
T& ArrayList<T>::get(int index)
{
  if (index < 0 || index >= _length) {
    throw std::logic_error("Indexed out of bounds");
  }
  return data[index];
}

template<typename T>
int ArrayList<T>::length() const
{
  return _length;
}

template<typename T>
void ArrayList<T>::resize()
{
  capacity *= 2;

  T* newPtr = new T[capacity];

  for (int i = 0; i < _length; i++) {
    newPtr[i] = data[i];
  }

  delete[] data;

  data = newPtr;
}

template<typename T>
void ArrayList<T>::push(T value)
{
  if (_length >= capacity) {
    resize(); // throw std::logic_error("Resize not implemented");
  }

  data[_length++] = value;
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other)
{
  _length = other._length;
  capacity = other._length;
  data = new T[capacity];

  for (int i = 0; i < _length; i++) {
    data[i] = other.data[i];
  }
}

template<typename T>
ArrayList<T> ArrayList<T>::operator=(const ArrayList<T>& other)
{
  if (this == &other) {
    return *this;
  }

  if (data != nullptr) {
    delete[] data;
  }

  _length = other._length;
  capacity = other._length;
  data = new T[capacity];

  for (int i = 0; i < _length; i++) {
    data[i] = other.data[i];
  }

  return *this;
}

#endif
