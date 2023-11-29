// -*- C++ -*-

//==============================================================================
/**
 * @file         Modulo_Command.h
 */
//==============================================================================

#ifndef _MODULO_COMMAND_H_
#define _MODULO_COMMAND_H_

#include  "Binary_Op_Command.h"

/*
 * @class Modulo_Command
 */
class Modulo_Command : public Binary_Op_Command
{
public:
  /// Default constructor.
  Modulo_Command (void);

  /// Destructor.
  ~Modulo_Command (void);

  /**
   * Get the remainder of division between two numbers.
   *
   * @param[in]       n1                  The first number
   * @param[in]       n2                  The second number
   * @return          The remainder after division of the first number by the second.
   */
  int evaluate (int n1, int n2) const;
};

#endif
