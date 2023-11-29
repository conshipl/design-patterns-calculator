#include "Modulo_Node.h"

Modulo_Node::Modulo_Node (void)
  : Binary_Expr_Node ()
{

}

Modulo_Node::Modulo_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (right, left)
{

}

Modulo_Node::~Modulo_Node (void)
{

}

void Modulo_Node::accept (Expr_Node_Visitor & v)
{
  v.Visit_Modulo_Node(*this);
}