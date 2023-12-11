#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include "Expr_Node.h"

class Expr_Builder
{
public:
  Expr_Builder (void);
  virtual ~Expr_Builder (void) = 0;

  virtual void start_expression (void) = 0;
  virtual void build_add_operator (void) = 0;
  virtual void build_divide_operator (void) = 0;
  virtual void build_modulo_operator (void) = 0;
  virtual void build_multiply_operator (void) = 0;
  virtual void build_number (int n) = 0;
  virtual void build_parenthesis (void) = 0;
  virtual void handle_parenthesis (void) = 0;
  virtual void build_subtract_operator (void) = 0;

  virtual Expr_Node * get_expression (void) = 0;
};

#endif
