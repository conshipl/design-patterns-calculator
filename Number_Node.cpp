#include "Number_Node.h"

Number_Node::Number_Node (int num)
  : value_ (num)
{

}

Number_Node::~Number_Node (void)
{

}

void Number_Node::accept (Expr_Node_Visitor & v)
{
  v.Visit_Number_Node(*this);
}
