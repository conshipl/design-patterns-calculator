inline
Expr_Node * Binary_Expr_Node::get_right_child (void) const
{
  return right_;
}

inline
void Binary_Expr_Node::set_right_child (Expr_Node * node)
{
  right_ = node;
}

inline
Expr_Node * Binary_Expr_Node::get_left_child (void) const
{
  return left_;
}

inline
void Binary_Expr_Node::set_left_child (Expr_Node * node)
{
  left_ = node;
}
