// -*- C++ -*-

//==============================================================================
/**
 * @file         Add_Command.h
 */
//==============================================================================

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include  "Binary_Op_Command.h"

/**
 * @class Add_Command
 */
class Add_Command : public Binary_Op_Command
{
public:
  /// Default constructor.
  Add_Command (void);

  /// Destructor.
  ~Add_Command (void);

  /**
   * Add two numbers.
   *
   * @param[in]       n1                  The first number
   * @param[in]       n2                  The second number
   * @return          The sum of the two numbers
   */
  int evaluate (int n1, int n2) const;
};

#endif
