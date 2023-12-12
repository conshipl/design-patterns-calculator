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
 * Implementation of a calculator that excepts expressions in the form '5 + ( 6 - 7)',
 * chooses a strategy: Postfix or Expression Tree (currently does Expression Tree for
 * assignment 4), parses and evaluates the expression with the chosen strategy and
 * returns a result until the user enters 'QUIT'.
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
   * postfix or an expression tree, evaluate using the strategy and output the result. 
   * Repeat until user enters 'QUIT'.
   */
  void execute(void);

  /**
   * Asks the user to enter an infix expression.
   *
   * @return          The user entered infix expression as a string
   */
  std::string get_equation(void);

  /*
   * Processes the user input expression and determines the suitable strategy.
   *
   * @param[in]       expr          The user entered infix expression as a string
   * @return          The determined evaluation strategy (postfix or tree)
   */
  Expr_Evaluator_Strategy * preprocess(std::string & expr);
};

#endif
