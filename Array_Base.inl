// -*- C++ -*-

//
// size
//
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
  return cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
  return max_size_;
}
