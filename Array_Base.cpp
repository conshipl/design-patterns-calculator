#include "Array_Base.h"
#include <stdexcept>
#include <iostream>

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void)
  : data_ (new T[5]),
    cur_size_ (5),
    max_size_ (5),
    shallow_copy_ (false)
{

}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
  : data_ (new T[length]),
    cur_size_ (length),
    max_size_ (length),
    shallow_copy_ (false)
{

}

//
// Array_Base (size_t, fill element)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
  : Array_Base (length)
{
  for (size_t i = 0; i < length; ++i){
    data_[i] = fill;
  }
}

// Array_Base (const Array_Base &)
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
  : data_ (new T[array.max_size_]),
    cur_size_ (array.cur_size_),
    max_size_ (array.max_size_),
    shallow_copy_ (array.shallow_copy_)
{
  for (size_t i = 0; i < max_size_; ++i){
    data_[i] = array[i];
  }
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
  if (!shallow_copy_){
    delete [] data_;
  }

  data_ = nullptr;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
  if (this != &rhs){

    if (max_size_ < rhs.cur_size_){
      delete [] data_;

      data_ = new T[rhs.max_size_];
      cur_size_ = rhs.cur_size_;
      max_size_ = rhs.max_size_;
    }

    for (size_t i = 0; i < max_size_; ++i){
      data_[i] = rhs[i];
    }
  }

  return *this;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
  isValidIndex(index);
  return data_[index];
}

//
// operator []
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
  isValidIndex(index);
  return data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
  isValidIndex(index);
  return data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
  isValidIndex(index);
  data_[index] = value;
}

//
// find (T)
//
template <typename T>
int Array_Base <T>::find (T value) const
{
  return find(value, 0);
}

//
// find (T, size_t)
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
  isValidIndex(start);

  for (size_t i = start; i < cur_size_; ++i){
    
    if (data_[i] == val){
      return i;
    }
  }

  return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
  if (this == &rhs){
    return true;
  }

  if (cur_size_ == rhs.cur_size_){
    
    for (size_t i = 0; i < cur_size_; ++i){
    
      if (data_[i] != rhs[i]){
        return false;
      }

    }

    return true;
  }

  return false;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
  return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
  for (size_t i = 0; i < cur_size_; ++i){
    data_[i] = value;
  }
}

//
// reverse
//
template <typename T>
void Array_Base <T>::reverse (void)
{
  size_t i = 0;
  size_t j = cur_size_ - 1;

  while (i < j){
    T temp = data_[i];
    data_[i] = data_[j];
    data_[j] = temp;
    ++i;
    --j;
  }
}

//
// slice (size_t)
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin) const
{
  isValidIndex(begin);
  Array_Base sliced = Array_Base();

  sliced.data_ = data_ + begin;
  sliced.cur_size_ = cur_size_ - begin;
  sliced.max_size_ = sliced.cur_size_;
  sliced.shallow_copy_ = true;

  return sliced;
}

//
// slice (size_t, size_t)
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin, size_t end) const
{
  isValidIndex(begin);
  isValidIndex(end);
  Array_Base sliced = Array_Base();

  sliced.data_ = data_ + begin;
  sliced.cur_size_ = end - begin;
  sliced.max_size_ = sliced.cur_size_;
  sliced.shallow_copy_ = true;

  return sliced;
}

//
// isValidIndex (size_t)
//
template <typename T>
void Array_Base <T>::isValidIndex(size_t index) const
{
  if (index < 0 || index >= cur_size_){
    throw std::out_of_range("Invalid index value.");
  }
}
