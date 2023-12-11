// -*- C++ -*-

//==============================================================================
/**
 * @file         Calculator.h
 */
//==============================================================================

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "ExprTree_Evaluator_Strategy.h"
#include "Postfix_Evaluator_Strategy.h"

/*
 * @class Calculator
 *
 * Implementation of a calculator the excepts expressions in the form '5 + ( 6 - 7)',
 * converts them from infix to postfix, evalautes the postfix expression, and returns
 * an integer result.
 *
 */
class Calculator
{
public:
  /// Default constructor.
  Calculator(void);

  /// Destructor.
  ~Calculator(void);

  /**
   * Core of the calculator program; ask user to enter an equation, convert it to 
   * postfix, evaluate the postfix, then return the result. Repeat until 'QUIT'.
   */
  void execute(void);

  /**
   * Asks the user to enter an infix expression.
   *
   * @return          The user entered infix expression as a string
   */
  std::string get_equation(void);

  Expr_Evaluator_Strategy * preprocess(std::string & expr);
};

#endif
