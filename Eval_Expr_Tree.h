#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
  Eval_Expr_Tree (void);
  virtual ~Eval_Expr_Tree (void);

  virtual void Visit_Add_Node (const Add_Node & node);
  virtual void Visit_Divide_Node (const Divide_Node & node);
  virtual void Visit_Modulo_Node (const Modulo_Node & node);
  virtual void Visit_Multiply_Node (const Multiply_Node & node);
  virtual void Visit_Number_Node (const Number_Node & node);
  virtual void Visit_Subtract_Node (const Subtract_Node & node);

  int result (void) const;

private:
  int result_;
};

#endif
