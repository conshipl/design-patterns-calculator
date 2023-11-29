// -*- C++ -*-

//==============================================================================
/**
 * @file         Subtract_Command.h
 */
//==============================================================================

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include  "Binary_Op_Command.h"

/**
 * @class Subtract_Command
 */
class Subtract_Command : public Binary_Op_Command
{
public:
  /// Default constructor.
  Subtract_Command (void);

  /// Destructor.
  ~Subtract_Command (void);

  /**
   * Subtract two numbers.
   *
   * @param[in]       n1                  The first number
   * @param[in]       n2                  The second number
   * @return          The difference of the first number minus the second
   */
  int evaluate (int n1, int n2) const;
};

#endif
