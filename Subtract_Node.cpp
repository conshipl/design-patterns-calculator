#include "Subtract_Node.h"

Subtract_Node::Subtract_Node (void)
  : Binary_Expr_Node ()
{

}

Subtract_Node::Subtract_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (right, left)
{

}

Subtract_Node::~Subtract_Node (void)
{

}

void Subtract_Node::accept (Expr_Node_Visitor & v)
{
  v.Visit_Subtract_Node(*this);
}
