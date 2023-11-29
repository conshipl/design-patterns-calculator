template <typename T>
inline
size_t Queue <T>::size (void) const
{
  return current_size_;
}

template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
  return (current_size_ == 0);
}
