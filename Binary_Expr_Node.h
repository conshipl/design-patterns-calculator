#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node
{
public:
  Binary_Expr_Node (void);
  Binary_Expr_Node (int precedence);
  Binary_Expr_Node (Expr_Node * right, Expr_Node * left);
  Binary_Expr_Node (int precedence, Expr_Node * right, Expr_Node * left);
  virtual ~Binary_Expr_Node (void);
 
  Expr_Node * get_right_child (void) const;
  void set_right_child (Expr_Node * node);
  Expr_Node * get_left_child (void) const;
  void set_left_child (Expr_Node * node);

  virtual int accept (Expr_Node_Visitor & v) = 0;

protected:
  Expr_Node * right_;
  Expr_Node * left_;
};

#include "Binary_Expr_Node.inl"

#endif
