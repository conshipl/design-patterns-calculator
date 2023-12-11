#ifndef _EXPRTREE_EVALUATOR_STRATEGY_H_
#define _EXPRTREE_EVALUATOR_STRATEGY_H_

#include "Expr_Evaluator_Strategy.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"
#include <sstream>

class ExprTree_Evaluator_Strategy : public Expr_Evaluator_Strategy
{
public:
  ExprTree_Evaluator_Strategy(void);
  virtual ~ExprTree_Evaluator_Strategy(void);

  virtual bool parse_expression(const std::string & expr);
  virtual void evaluate_expression(void);

  virtual bool is_valid_expression(void) const;
  virtual size_t number_of_operators(void) const;
  virtual size_t number_of_operands(void) const;

private:
  Expr_Builder * builder_;
};

#endif
