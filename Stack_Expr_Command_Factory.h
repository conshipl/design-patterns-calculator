// -*- C++ -*-

//==============================================================================
/**
 * @file         Stack_Expr_Command_Factory.h
 */
//==============================================================================

#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

/*
 * @class Stack_Expr_Command_Factory
 */
class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       s         Reference to a stack
   */
  Stack_Expr_Command_Factory(Stack <int> & s);

  /// Destructor.
  ~Stack_Expr_Command_Factory(void);
  
  /**
   * Create an Add_Command object.
   *
   * @return          Pointer to Add_Command object
   */
  Add_Command * create_add_command(void);

  /**
   * Create a Subtract_Command object.
   *
   * @return          Pointer to Subtract_Command object
   */
  Subtract_Command * create_subtract_command(void);

  /**
   * Create a Multiply_Command object.
   *
   * @return          Pointer to Multiply_Command object
   */
  Multiply_Command * create_multiply_command(void);

  /**
   * Create a Divide_Command object.
   *
   * @return          Pointer to Divide_Command object
   */
  Divide_Command * create_divide_command(void);

  /**
   * Create a Modulo_Command object.
   *
   * @return          Pointer to Modulo_Command object
   */
  Modulo_Command * create_modulo_command(void);

  /**
   * Create a Parenthesis_Command object.
   *
   * @return          Pointer to Parenthesis_Command object
   */
  Parenthesis_Command * create_parenthesis_command(void);

  /**
   * Create a Number_Command object.
   *
   * @param[in]       num        The value of the number stored in the Number_Command
   * @return          Pointer to Number_Command object
   */
  Number_Command * create_number_command(int num);
  
private:
  /*
   * Store Command objects for each operation and return pointers to them in
   * each create_command() method since creating a new instance each time is
   * unnecessary (Flyweight Pattern).
   *
   * Only numbers will get a new instance each time.
   */
  Stack <int> & s_;
  Add_Command * add_;
  Subtract_Command * subtract_;
  Multiply_Command * multiply_;
  Divide_Command * divide_;
  Modulo_Command * modulo_;
  Parenthesis_Command * parenthesis_;
};

#endif
