#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include "Expr_Node_Visitor.h"

class Expr_Node 
{
public:
  Expr_Node (void);
  virtual ~Expr_Node (void);

  virtual void accept (Expr_Node_Visitor & v) = 0;
};

#endif
