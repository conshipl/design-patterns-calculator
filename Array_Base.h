// -*- C++ -*-

//==============================================================================
/**
 * @file         Array_Base.h
 */
//==============================================================================

#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>         // for size_t definition

/**
 * @class Array_Base
 *
 * Implementation of base array class for type T elements.
 */
template <typename T>
class Array_Base
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Array_Base (void);

  /**
   * Initializing constructor.
   *
   * @param[in]         length        Initial size
   */
  Array_Base (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]         length        Initial size
   * @param[in]         fill          Initial value for each element
   */
  Array_Base (size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]         arr           The source array
   */
  Array_Base (const Array_Base & arr);

  /// Destructor
  ~Array_Base (void);

  /**
   * Assignment operation
   *
   * @param[in]         rhs           Right-hand size of equal sign
   * @return            Reference to self
   */
  const Array_Base & operator = (const Array_Base & rhs);

  /**
   * Retrieve the current size of the array.
   *
   * @return            The current size
   */
  size_t size (void) const;

  /**
   * Retrieve the maximum size of the array.
   *
   * @return            The maximum size
   */
  size_t max_size (void) const;

  /**
   * Get the element at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]         index              Zero-based location
   * @exception         std::out_of_range  Invalid index value
   */
  T & operator [] (size_t index);

  /**
   * @overload
   *
   * The returned element is not modifiable.
   */
  const T & operator [] (size_t index) const;

  /**
   * Get the element at the specified index. If the index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]         index              Zero-based location
   * @return            Element at index
   * @exception         std::out_of_range  Invalid index value
   */   
  T get (size_t index) const;

  /**
   * Set the element at the specified index. If the index is not
   * within range of the array, then std::out_of_range exception is
   * thrown.
   *
   * @param[in]         index              Zero-based location
   * @param[in]         value              New value for element
   * @exception         std::out_of_range  Invalid index value
   */
  void set (size_t index, T value);

  /**
   * Locate the specified element in the array. The index of the first
   * occurrence of the element is returned. If the element is not found
   * in the array, then -1 is returned.
   *
   * @param[in]         element            Element to search for
   * @return            Index value of the element
   * @retval            -1                 Element not found
   */
  int find (T element) const;

  /**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]         element            Element to search for
   * @param[in]         start              Index to begin search
   * @return            Index value of the first occurrence
   * @retval            -1                 Element not found
   * @exception         std::out_of_range  Invalid index
   */
  int find (T element, size_t start) const;

  /**
   * Test the array for equality.
   *
   * @param[in]         rhs                Right hand side of the equal sign
   * @retval            true               Left side is equal to right side
   * @retval            false              Left side is not equal to right side
   */
  bool operator == (const Array_Base & rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]         rhs                Right hand side of not equal sign
   * @retval            true               Left side is not equal to right side
   * @retval            false              Left side is equal to right side
   */
  bool operator != (const Array_Base & rhs) const;

  /**
   * Fill the contents of the array.
   *
   * @param[in]         element            Fill element
   */
  void fill (T element);

  /// Reverse the contents of the array such that the first element is now
  /// the last element and the last element is the first element.
  void reverse (void);

  /**
   * The slice() method returns a shallow copy of a portion of an array into
   * a new array object selected from begin to end (end not included). The original
   * array will not be modified.
   *
   * @param[in]         begin              The starting index
   * @return            A new Array_Base object
   */
  Array_Base slice (size_t begin) const;

  /**
   * @overload
   *
   * @param[in]         begin              The starting index
   * @param[in]         end                The ending index
   * @return            A new Array_Base object
   */
  Array_Base slice (size_t begin, size_t end) const;

protected:
  /**
   * Check if the provided index is within the valid range; throw std::out_of_range
   * exception if not.
   *
   * @param[in]         index              The index to be checked
   * @exception         std::out_of_range  Invalid index
   */
  void isValidIndex (size_t index) const;

  /// Pointer to the actual data.
  T * data_;

  /// Current size of the array.
  size_t cur_size_;

  /// Maximum size of the array.
  size_t max_size_;

  /**
   * Boolean flag to determine if Array_Base instance is a shallow copy. When
   * destructor is called, if shallow_copy_ is true, the array's data_ pointer will
   * be set to nullptr and no further action is taken. If false, the former will
   * occur and delete [] data_ will be called.
   */
  bool shallow_copy_;

};

#include "Array_Base.inl"
#include "Array_Base.cpp"

#endif
