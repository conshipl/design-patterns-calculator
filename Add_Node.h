#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include "Binary_Expr_Node.h"

class Add_Node : public Binary_Expr_Node
{
public:
  Add_Node (void);
  ~Add_Node (void);

  virtual void accept (Expr_Node_Visitor & v);
};

#endif
