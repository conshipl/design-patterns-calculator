// -*- C++ -*-

//==============================================================================
/**
 * @file         Number_Command.h
 */
//==============================================================================

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include  "Expr_Command.h"

/*
 * @class Number_Command
 */
class Number_Command : public Expr_Command
{
public:
  /// Default constructor.
  Number_Command (int num);

  /// Destructor.
  ~Number_Command (void);

  /**
   * Push value_ onto stack s.
   *
   * @param[in]       s                  Reference to a stack
   */
  void execute (Stack <int> & s);
 
private:
  /// Integer value of the number.
  int value_;
};

#endif
