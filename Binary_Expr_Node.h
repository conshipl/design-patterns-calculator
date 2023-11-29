#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node
{
public:
  Binary_Expr_Node (void);
  Binary_Expr_Node (Expr_Node * right, Expr_Node * left);
  virtual ~Binary_Expr_Node (void);

  virtual void accept (Expr_Node_Visitor & v) = 0;

protected:
  Expr_Node * right_;
  Expr_Node * left_;
};

#endif
