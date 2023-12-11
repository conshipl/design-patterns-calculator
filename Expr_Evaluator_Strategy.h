#ifndef _EXPR_EVALUATOR_STRATEGY_H_
#define _EXPR_EVALUATOR_STRATEGY_H_

#include <string>
#include <cstring>

class Expr_Evaluator_Strategy
{
public:
  Expr_Evaluator_Strategy(void);
  virtual ~Expr_Evaluator_Strategy(void) = 0;

  virtual bool parse_expression(const std::string & expr) = 0;
  virtual void evaluate_expression(void) = 0;

  virtual bool is_valid_expression(void) const = 0;
  virtual size_t number_of_operators(void) const = 0;
  virtual size_t number_of_operands(void) const = 0;
};

#endif
