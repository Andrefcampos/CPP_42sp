
#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "../includes/Array.hpp"
# include <stdexcept>

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
Array<T>::Array(unsigned int const &num) : _data(new T[num]()), _size(num) {}

template <typename T>
Array<T>::Array(Array const &param) : _data(new T[param._size]), _size(param._size) {
  for (std::size_t i = 0; i < _size; i++) {
    _data[i] = param._data[i];
  }
}

template <typename T>
unsigned int Array<T>::size(void) const {
  return this->_size;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &param) {
  if (this != &param) {
    delete[] _data;
    _size = param._size;
    _data = new T[_size];
    for (int i = 0; (size_t)i < _size; i++) {
      _data[i] = param._data[i];
    }
  }
  return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int const &param) {
  if (param >= this->_size) {
    throw std::out_of_range("Index out of range");
  }
  return this->_data[param];
}

template <typename T>
const T &Array<T>::operator[](unsigned int const &param) const {
  if (param >= this->_size) {
    throw std::out_of_range("Index out of range");
  }
  return this->_data[param];
}

#endif
