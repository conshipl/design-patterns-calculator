// -*- C++ -*-

//==============================================================================
/**
 * @file         Divide_Command.h
 */
//==============================================================================

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include  "Binary_Op_Command.h"
#include <exception>

/*
 * @class Divide_Command
 */
class Divide_Command : public Binary_Op_Command
{
public:

  /*
   * @class division_by_zero_exception
   *
   * Exception thrown to indicate division by zero.
   */
  class division_by_zero_exception : public std::exception
  {
  public:
    /// Default constructor.
    division_by_zero_exception (void)
      : std::exception () { }
  };

  /// Default constructor.
  Divide_Command (void);

  /// Destructor.
  ~Divide_Command (void);

  /**
   * Divide two numbers.
   *
   * @param[in]       n1                  The first number
   * @param[in]       n2                  The second number
   * @return          The quotient of the first number divided by the second
   */
  int evaluate (int n1, int n2) const;
};

#endif
