#include "Divide_Node.h"

//
// Divide_Node
//
Divide_Node::Divide_Node (void)
  : Binary_Expr_Node (1)
{

}

//
// Divide_Node w/ children
//
Divide_Node::Divide_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (1, right, left)
{

}

//
// ~Divide_Node
//
Divide_Node::~Divide_Node (void)
{

}

//
// accept
//
int Divide_Node::accept (Expr_Node_Visitor & v)
{
  return v.Visit_Divide_Node(*this);
}
