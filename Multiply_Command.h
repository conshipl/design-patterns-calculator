// -*- C++ -*-

//==============================================================================
/**
 * @file         Multiply_Command.h
 */
//==============================================================================

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include  "Binary_Op_Command.h"

/*
 * @class Multiply_Command
 */
class Multiply_Command : public Binary_Op_Command
{
public:
  /// Default constructor.
  Multiply_Command (void);

  /// Destructor.
  ~Multiply_Command (void);

  /**
   * Multiply two numbers.
   *
   * @param[in]       n1                  The first number
   * @param[in]       n2                  The second number
   * @return          The product of the two numbers
   */
  int evaluate (int n1, int n2) const;
};

#endif
