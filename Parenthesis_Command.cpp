#include "Parenthesis_Command.h"

//
// Parenthesis_Command
//
Parenthesis_Command::Parenthesis_Command (void)

  // parenthesis have highest precedence (0 thru 2), may have to adjust if adding unary later
  : Expr_Command (2)
{

}

//
// ~Parenthesis_Command
//
Parenthesis_Command::~Parenthesis_Command (void)
{

}

//
// execute
//
void Parenthesis_Command::execute (Stack <int> & s)
{
  // algorithm handles parentheses, just needed an Expr_Command * placeholder
}
