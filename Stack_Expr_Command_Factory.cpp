#include "Stack_Expr_Command_Factory.h"

//
// Stack_Expr_Command_Factory
//
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack <int> & s)

  // initialize objects to be spit out of the factory (flyweight)
  : s_ (s),
    add_ (new Add_Command),
    subtract_ (new Subtract_Command),
    multiply_ (new Multiply_Command),
    divide_ (new Divide_Command),
    modulo_ (new Modulo_Command),
    parenthesis_ (new Parenthesis_Command)
{

}

//
// ~Stack_Expr_Command_Factory
//
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{
  
  delete add_;
  delete subtract_;
  delete multiply_;
  delete divide_;
  delete modulo_;
  delete parenthesis_;
}

//
// create_add_command
//
Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
  return this->add_;
}

//
// create_subtract_command
//
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
  return this->subtract_;
}

//
// create_multiply_command
//
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
  return this->multiply_;
}

//
// create_divide_command
//
Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
  return this->divide_;
}

//
// create_modulo_command
//
Modulo_Command * Stack_Expr_Command_Factory::create_modulo_command (void)
{
  return this->modulo_;
}

//
// create_parenthesis_command
//
Parenthesis_Command * Stack_Expr_Command_Factory::create_parenthesis_command (void)
{
  return this->parenthesis_;
}

//
// create_number_command
//
Number_Command * Stack_Expr_Command_Factory::create_number_command (int num)
{

  // numbers get unique object each time
  return new Number_Command(num);
}
