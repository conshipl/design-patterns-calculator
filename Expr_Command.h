// -*- C++ -*-

//==============================================================================
/**
 * @file         Expr_Command.h
 */
//==============================================================================

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack.h"

/*
 * @class Expr_Command
 */
class Expr_Command
{
public:
  /// Default constructor.
  Expr_Command (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       precedence       In what order the command should be executed
   */
  Expr_Command (int precedence);

  /// Default destructor.
  ~Expr_Command (void);

  /**
   * Abstract method.
   *
   * @param[in]       s           Reference to a stack
   */
  virtual void execute (Stack <int> & s) = 0;

  /**
   * Get the precedence of the command.
   *
   * @return          The precedence of the command
   */
  int get_precedence (void);
private:
  /// In what order (relative to other commands) the command should be executed
  int precedence_;
};

#include "Expr_Command.inl"
#endif
