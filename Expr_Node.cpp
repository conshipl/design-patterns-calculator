#include "Expr_Node.h"

Expr_Node::Expr_Node (void)
  : precedence_ (0)
{

}

Expr_Node::Expr_Node (int precedence)
  : precedence_ (precedence)
{

}

Expr_Node::~Expr_Node (void)
{

}

int Expr_Node::get_precedence (void)
{
  return precedence_;
}
