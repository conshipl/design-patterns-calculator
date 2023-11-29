#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for arbitrary elements.
 * 
 * Initially was going to implement Queue built on circular Array, but it seemed
 * like overkill for this submission. Can change this moving forward if desired.
 */
template <typename T>
class Queue
{
public:

  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]        msg            Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & q);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]        rhs            Right-hand side of operator
   * @return           Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Enqueue a new element into the queue. The element is inserted
   * after all the other elements in the list.
   *
   * @param[in]        element        Element to add to the list
   */
  void enqueue (T element);

  /**
   * Get the front-most element of the queue. If there are no elements
   * in the queue, then the queue_is_empty exception is thrown.
   *
   * @return Element in front of the queue.
   * @exception        empty_exception    The queue is empty
   */
  T dequeue (void);

  /**
   * Test if the queue is empty
   *
   * @retval           true           The queue is empty
   * @retval           false          The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of elements in the queue.
   *
   * @return           Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);

private:
  
  // Instance of Array class that can be manipulated by Queue
  Array<T> arr_;

  // Keeps track of front of Queue for dequeue operations
  size_t head_;

  // Keeps track of back of Queue for enqueue operations
  size_t tail_;

  // Keeps track of number of elements currently in the Queue
  size_t current_size_;
};

#include "Queue.inl"
#include "Queue.cpp"

#endif
