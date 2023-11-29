// -*- C++ -*-

//==============================================================================
/**
 * @file         Binary_Op_Command.h
 */
//==============================================================================

#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include <iostream>

/*
 * @class Binary_Op_Command
 */
class Binary_Op_Command : public Expr_Command
{
public:
  /// Default constructor.
  Binary_Op_Command (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       precedence        The precedence of the command
   */
  Binary_Op_Command (int precedence);
  
  /// Destructor.
  ~Binary_Op_Command (void);

  /**
   * Pop the first two numbers off the top of a stack, do something with
   * them, then push the result back onto the stack..
   *
   * @param[in]       s                  Reference to a stack.
   */
  void execute (Stack <int> & s);

  /**
   * Abstract method..
   *
   * @param[in]       n1                  The first number
   * @param[in]       n2                  The second number
   * @return          The result of some operation on the two numbers
   */
  virtual int evaluate (int n1, int n2) const = 0;

};

#endif
