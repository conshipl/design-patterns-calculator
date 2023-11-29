#include "Number_Command.h"

//
// Number_Command
//
Number_Command::Number_Command (int num)
  : Expr_Command (9),
    value_ (num)
{

}

//
// ~Number_Command
//
Number_Command::~Number_Command (void)
{

}

//
// execute
//
void Number_Command::execute (Stack <int> & s)
{
  s.push(value_);
}
