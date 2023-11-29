// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
// COMMENT You are using the copy constructor to initialize the array. There
// is no need to explicitly call a constuctor if you are going to use the
// default constructor to initilize the member variable.
//
// REPLY This makes sense; change has been implemented.
  : top_ (-1)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
// COMMENT This is not the correct way to initialize a member variable. Just
// write arr_ (stack.arr_). This approach is creating a temp variable, and then calling
// the copy constructor.
//
// REPLY Understood, change has been implemented.
  : arr_ (stack.arr_),
    top_ (stack.top_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
  // If trying to push an element would cause index out_of_range exception, resize Array
  if (top_ + 1 == arr_.size()){
    arr_.resize(top_ * 2);
  }

  // Increment top_ then assign element to new location
  ++top_;
  arr_[top_] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
  if (is_empty()){
    throw empty_exception(); //"Cannot pop; stack is empty.");
  }

  --top_;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  if (this != &rhs){
    
    top_ = -1;

    arr_.resize(rhs.size());

    for (size_t i = 0; i <= rhs.top_; ++i){
      push(rhs.arr_[i]);
    }

  }

  return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
  // Stack doesn't actually need to be cleared, can just reset the top and overwrite data
  top_ = 0;
}
