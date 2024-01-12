#include "Number_Node.h"

//
// Number_Node
//
Number_Node::Number_Node (int num)
  : Expr_Node (9),
    value_ (num)
{

}

//
// ~Number_Node
//
Number_Node::~Number_Node (void)
{

}

//
// set_value
//
void Number_Node::set_value (int num)
{
  value_ = num;
}

//
// get_value
//
int Number_Node::get_value (void) const
{
  return value_;
}

//
// accept
//
int Number_Node::accept (Expr_Node_Visitor & v)
{
  return v.Visit_Number_Node(*this);
}
