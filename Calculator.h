// -*- C++ -*-

//==============================================================================
/**
 * @file         Calculator.h
 */
//==============================================================================

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include <sstream>
#include <string>

#include "Stack_Expr_Command_Factory.h"
#include "Array.h"
#include "Queue.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"
#include "ExprTree_Evaluator_Strategy.h"

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

  Calculator(Expr_Builder * builder);

  /// Destructor.
  ~Calculator(void);

  /**
   * Core of the calculator program; ask user to enter an equation, convert it to 
   * postfix, evaluate the postfix, then return the result. Repeat until 'QUIT'.
   */
  void execute(void);

  /**
   * Convert an infix expression to postfix.
   *
   * @param[in]       infix            Infix expression as a string
   * @param[in]       factory          Factory to produce commands
   * @param[in]       postfix          Queue that stores postfix expression as commands
   */
  void infix_to_postfix(const std::string & infix, Stack_Expr_Command_Factory & factory, Queue<Expr_Command *> & postfix);

  /**
   * Asks the user to enter an infix expression.
   *
   * @return          The user entered infix expression as a string
   */
  std::string get_equation(void);

  bool parse_expr(const std::string & infix);
  int evaluate(const std::string & infix);
  
  /// DELETE THIS; MERGE WITH OTHER EXECUTE FOR STRATEGY PATTERN
  void execute_tree(void);

private:
  Expr_Builder * builder_;
};

#endif
