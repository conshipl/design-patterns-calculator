#include "Divide_Node.h"

Divide_Node::Divide_Node (void)
  : Binary_Expr_Node ()
{

}

Divide_Node::Divide_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (right, left)
{

}

Divide_Node::~Divide_Node (void)
{

}

void Divide_Node::accept (Expr_Node_Visitor & v)
{
  v.Visit_Divide_Node(*this);
}
