#include "Multiply_Node.h"

//
// Multiply_Node
//
Multiply_Node::Multiply_Node (void)
  : Binary_Expr_Node (1)
{

}

//
// Multiply_Node w/ children
//
Multiply_Node::Multiply_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (1, right, left)
{

}

//
// ~Multiply_Node
//
Multiply_Node::~Multiply_Node (void)
{

}

//
// accept
//
int Multiply_Node::accept (Expr_Node_Visitor & v)
{
  return v.Visit_Multiply_Node(*this);
}
