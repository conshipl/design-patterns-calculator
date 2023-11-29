#include "Expr_Command.h"

//
// Expr_Command
//
Expr_Command::Expr_Command (void)
  : precedence_ (0)
{

}

//
// Expr_Command (int)
//
Expr_Command::Expr_Command (int precedence)
  : precedence_ (precedence)
{

}

//
// ~Expr_Command
//
Expr_Command::~Expr_Command (void)
{

}
