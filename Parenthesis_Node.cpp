#include "Parenthesis_Node.h"

Parenthesis_Node::Parenthesis_Node (void)
  : Binary_Expr_Node (2)
{

}

Parenthesis_Node::~Parenthesis_Node (void)
{

}

int Parenthesis_Node::accept (Expr_Node_Visitor & v)
{
  return 0;
}
