#ifndef _DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include "Binary_Expr_Node.h"

class Divide_Node : public Binary_Expr_Node
{
public:
  Divide_Node (void);
  Divide_Node (Expr_Node * right, Expr_Node * left)
  ~Divide_Node (void);

  virtual void accept (Expr_Node_Visitor & v);
};

#endif
