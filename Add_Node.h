#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Add_Node : public Binary_Expr_Node
{
public:
  Add_Node (void);
  Add_Node (Expr_Node * right, Expr_Node * left);
  ~Add_Node (void);

  virtual int accept (Expr_Node_Visitor & v);
};

#endif
