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
