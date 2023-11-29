// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
  // top_ starts at -1, so initial size will therefore be 0
  return (top_ + 1);
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
  if (is_empty()){
    throw empty_exception(); //"Cannot return top; stack is empty.");
  }

  return arr_[top_];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
  return (size() == 0);
}
