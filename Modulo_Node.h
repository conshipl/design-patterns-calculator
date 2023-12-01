#ifndef _MODULO_NODE_H_
#define _MODULO_NODE_H_

#include "Binary_Expr_Node.h"

class Modulo_Node : public Binary_Expr_Node
{
public:
  Modulo_Node (void);
  Modulo_Node (Expr_Node * right, Expr_Node * left);
  ~Modulo_Node (void);

  virtual void accept (Expr_Node_Visitor & v);
};

#endif
