#include "Add_Node.h"

Add_Node::Add_Node (void)
  : Binary_Expr_Node ()
{

}

Add_Node::Add_Node (Expr_Node * right, Expr_Node * left)
  : Binary_Expr_Node (right, left)
{

}

Add_Node::~Add_Node (void)
{

}

void Add_Node::accept (Expr_Node_Visitor & v)
{
  v.Visit_Add_Node(*this);
}