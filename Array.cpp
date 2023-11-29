// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

//
// Array
//
template <typename T>
Array <T>::Array (void)
  : Array_Base<T>()
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
  : Array_Base<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
  : Array_Base<T>(length, fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
  : Array_Base<T>(array)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
  if (this != &rhs){
    
    resize(rhs.max_size());

    for (size_t i = 0; i < this->max_size(); ++i){
      this->set(i, rhs[i]);
    }
  }

  return *this;
}


//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
  if (new_size > this->max_size()){
    
    T* temp = new T[new_size];

    for (size_t i = 0; i < this->max_size(); ++i){
      temp[i] = this->data_[i];
    }

    delete [] this->data_;
    this->data_ = temp;
    this->cur_size_ = new_size;
    this->max_size_ = new_size;

  } else if (new_size <= this->max_size()){
    this->cur_size_ = new_size;
  }
}

//
// shrink
//
template <typename T>
void Array <T>::shrink (void)
{
  if (this->size() < this->max_size()){
    
    T* temp = new T[this->size()];

    for (size_t i = 0; i < this->size(); ++i){
      temp[i] = this->data_[i];
    }

    delete [] this->data_;
    this->data_ = temp;
    this->max_size_ = this->size();
  }
}
