
#include <exception>
#include <stdexcept>
using namespace std;

template<typename T>
class ArrayList {
private:
  unsigned int length = 0;
  unsigned int capacity = 0;
  T* data = nullptr;

public:
  ArrayList(int reserve_size);

  ~ArrayList();

  T& get(int index);

  void push(T value);
};

template<typename T>
ArrayList<T>::ArrayList(int reserve_size)
{
  length = 0;
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
  if (index < 0 || index >= length) {
    throw std::logic_error("Indexed out of bounds");
  }
  return data[index];
}

template<typename T>
void ArrayList<T>::push(T value)
{
  if (length >= capacity) {
    throw std::logic_error("Resize not implemented");
  }

  data[length++] = value;
}
