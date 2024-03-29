#include "Modulo_Node.h"

//
// Modulo_Node
//
Modulo_Node::Modulo_Node (void)
  : Binary_Expr_Node (1)
{

}

//
// Modulo_Node w/ children
//
Modulo_Node::Modulo_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (1, right, left)
{

}

//
// ~Modulo_Node
//
Modulo_Node::~Modulo_Node (void)
{

}

//
// accept
//
int Modulo_Node::accept (Expr_Node_Visitor & v)
{
  return v.Visit_Modulo_Node(*this);
}
