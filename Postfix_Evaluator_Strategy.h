// -*- C++ -*-

//==============================================================================
/**
 * @file         Postfix_Evaluator_Strategy.h
 */
//==============================================================================

#ifndef _POSTFIX_EVALUATOR_STRATEGY_H_
#define _POSTFIX_EVALUATOR_STRATEGY_H_

#include "Expr_Evaluator_Strategy.h"
#include "Stack_Expr_Command_Factory.h"
#include "Array.h"
#include "Queue.h"
#include <sstream>

class Postfix_Evaluator_Strategy : public Expr_Evaluator_Strategy
{
public:
  Postfix_Evaluator_Strategy(void);
  virtual ~Postfix_Evaluator_Strategy(void);

  virtual bool parse_expression(const std::string & expr);
  virtual void evaluate_expression(void);

  virtual bool is_valid_expression(void) const;
  virtual size_t number_of_operators(void) const;
  virtual size_t number_of_operands(void) const;

private:
  Stack <int> result_;
  Stack_Expr_Command_Factory * stack_factory_;
  Queue <Expr_Command *> postfix_;
};

#endif
