#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:
  Expr_Tree_Builder (void);
  virtual ~Expr_Tree_Builder (void);

  virtual void start_expression (void);

  virtual void build_add_operator (void);
  virtual void build_divide_operator (void);
  virtual void build_modulo_operator (void);
  virtual void build_multiply_operator (void);
  virtual void build_number (int n);
  virtual void build_subtract_operator (void);

  Expr_Node * get_expression (void);

private:
  Expr_Node * tree_;
};

#endif
