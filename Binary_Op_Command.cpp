#include "Binary_Op_Command.h"

//
// Binary_Op_Command
//
Binary_Op_Command::Binary_Op_Command (void)
  : Expr_Command (0)
{

}

//
// Binary_Op_Command (int)
//
Binary_Op_Command::Binary_Op_Command (int precedence)
  : Expr_Command (precedence)
{

}

//
// ~Binary_Op_Command
//
Binary_Op_Command::~Binary_Op_Command (void)
{

}

//
// execute
//
void Binary_Op_Command::execute (Stack <int> & s)
{
  /* Take the first two numbers off the top of the stack,
   * do something with them, then push the result back to
   * the stack.
   */	
  int n2 = s.top();
  s.pop();

  int n1 = s.top();
  s.pop();
  
  int result = this->evaluate(n1, n2);
  s.push(result);
}
