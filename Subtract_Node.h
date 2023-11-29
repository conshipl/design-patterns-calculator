#ifndef _SUBTRACT_NODE_H_
#define _SUBTRACT_NODE_H_

#include "Binary_Expr_Node.h"

class Subtract_Node : public Binary_Expr_Node
{
public:
  Subtract_Node (void);
  Subtract_Node (Expr_Node * right, Expr_Node * left)
  ~Subtract_Node (void);

  virtual void accept (Expr_Node_Visitor & v);
};

#endif
