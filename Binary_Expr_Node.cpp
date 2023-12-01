#include "Binary_Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node (void)
  : right_ (nullptr),
    left_ (nullptr)
{

}

Binary_Expr_Node::Binary_Expr_Node (int precedence)
  : Expr_Node (precedence),
    right_ (nullptr),
    left_ (nullptr)
{

}

Binary_Expr_Node::Binary_Expr_Node (Expr_Node * right, Expr_Node * left)
  : right_ (right),
    left_ (left)
{

}

Binary_Expr_Node::Binary_Expr_Node (int precedence, Expr_Node * right, Expr_Node * left)
  : Expr_Node (precedence),
    right_ (right),
    left_ (left)
{

}

Binary_Expr_Node::~Binary_Expr_Node (void)
{
  delete right_;
  delete left_;
}

Expr_Node * Binary_Expr_Node::get_right_child (void) const
{
  return right_;
}

void Binary_Expr_Node::set_right_child (Expr_Node * node)
{
  right_ = node;
}

Expr_Node * Binary_Expr_Node::get_left_child (void) const
{
  return left_;
}

void Binary_Expr_Node::set_left_child (Expr_Node * node)
{
  left_ = node;
}
