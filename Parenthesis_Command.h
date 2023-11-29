// -*- C++ -*-

//==============================================================================
/**
 * @file         Parenthesis_Command.h
 */
//==============================================================================

#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include  "Expr_Command.h"

// COMMENT: Create a design that does not require having parenthesis as
// as command object since parenthesis are not executed.
//
// REPLY: A family member has developed an illness and needed a procedure
// and I've been taking care of them the last three weeks. Between this
// and hosting Thanksgiving on Thursday, I just don't have the time to 
// redesign this program, unfortunately.
//
// I tried to think through it and come up with an easy/clever solution,
// but I couldn't think of anything. My possible solution was to change
// the algorithm a bit so that I could call the infix_to_postfix function
// recursively, and then when a parenthesis was encountered, it would go
// into the recursive sub-call and evaluate the inside of the parenthesis
// first.

/*
 * @class Parenthesis_Command
 */
class Parenthesis_Command : public Expr_Command
{
public:
  /// Default constructor.
  Parenthesis_Command (void);

  /// Destructor.
  ~Parenthesis_Command (void);

  /**
   * Do nothing, as parenthesis is just a placeholder.
   */
  void execute (Stack <int> & s);
};

#endif
