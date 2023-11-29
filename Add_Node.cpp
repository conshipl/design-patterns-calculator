#include "Add_Node.h"

Add_Node::Add_Node (void)
{

}

Add_Node::~Add_Node (void)
{

}

void Add_Node::accept (Expr_Node_Visitor & v)
{
  v.Visit_Add_Node(*this);
}
