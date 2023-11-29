//
// Queue
//
template <typename T>
Queue <T>::Queue (void)
// COMMENT You are using the copy constructor to initialize the array. There
// is no need to explicitly call a constuctor if you are going to use the
// default constructor to initilize the member variable.
  : head_ (0),
    tail_ (0),
    current_size_ (0)
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue)
// COMMENT This is not the correct way to initialize a member variable. Just
// write arr_ (queue.arr_). This approach is creating a temp variable, and then calling
// the copy constructor.
  : arr_ (queue.arr_),
    head_ (queue.head_),
    tail_ (queue.tail_),
    current_size_ (queue.current_size_)
{

}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{

}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    // COMMENT You are resizing the queue, but you are wasting space at the front of
    // the array. Fix your design so you use all the space in the array.
    //
    // REPLY Changed implementation so that if the tail_ reaches the end of the array
    // then we resize the array to double the # of elements and reset the head_ and
    // tail_ appropriately; else, carry-on as before.
  
  // If the tail equals the last index, resize the array, then increment tail and size
  if (current_size_ == (arr_.size())){
    arr_.resize(current_size_ * 2);
  }

  arr_[tail_] = element;
  tail_++;
  current_size_++;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
  if (is_empty()){
    throw empty_exception();
  }

    // COMMENT This solution will work, but you are wasting space at the front
    // of the array since those "unused" spaces will never be used again. Please
    // come up with a better design that uses memory more efficiently.
    //
    // REPLY Change implemented. Every dequeue, array elements are shifted one
    // position back, and tail_ and current_size_ are decremented.
    
  // Store element that needs returned so head can be incremented
  T element = arr_[head_];
  
  if (current_size_ > 1){
    for (size_t i = head_; i < current_size_ - 1; ++i){
      arr_[i] = arr_[i+1];
    }
  }
  
  --tail_;
  --current_size_;

  return element;
  
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
  if (this != &rhs){
    
      // COMMENT Could you not use the assignment operator on the array class
      // to copy over the elements.
      //
      // REPLY Change implemented.

    clear();
    arr_ = rhs.arr_;
    tail_ = rhs.tail_;
    current_size_ = rhs.current_size_;

  }

  return *this; 
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
  head_ = 0;
  tail_ = 0;
  current_size_ = 0;
}
