#include "Multiply_Node.h"

Multiply_Node::Multiply_Node (void)
  : Binary_Expr_Node ()
{

}

Multiply_Node::Multiply_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (right, left)
{

}

Multiply_Node::~Multiply_Node (void)
{

}

void Multiply_Node::accept (Expr_Node_Visitor & v)
{
  v.Visit_Multiply_Node(*this);
}
