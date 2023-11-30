#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node
{
public:
  Binary_Expr_Node (void);
  Binary_Expr_Node (Expr_Node * right, Expr_Node * left);
  virtual ~Binary_Expr_Node (void);

  // May not need this code, because of the novelty of these patterns to me
  // I'm not sure if Visitor will have access to protected member variables.
  // Will try it without this code first.
 
  /*Expr_Node * get_right_child (void);
  void set_right_child (Expr_Node * node);
  Expr_Node * get_left_child (void);
  void set_left_child (Expr_Node * node);*/

  virtual void accept (Expr_Node_Visitor & v) = 0;

protected:
  Expr_Node * right_;
  Expr_Node * left_;
};

#endif
