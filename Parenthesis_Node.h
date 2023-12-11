#ifndef _PARENTHESIS_NODE_H_
#define _PARENTHESIS_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Parenthesis_Node : public Binary_Expr_Node
{
public:
  Parenthesis_Node (void);
  ~Parenthesis_Node (void);

  virtual int accept (Expr_Node_Visitor & v);
};

#endif
