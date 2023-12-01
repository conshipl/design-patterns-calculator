#include "Number_Node.h"

Number_Node::Number_Node (int num)
  : value_ (num)
{

}

Number_Node::~Number_Node (void)
{

}

void Number_Node::set_value (int num)
{
  value_ = num;
}

int Number_Node::get_value (void) const
{
  return value_;
}

int Number_Node::accept (Expr_Node_Visitor & v)
{
  return v.Visit_Number_Node(*this);
}
