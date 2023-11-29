#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expr_Node.h"

class Number_Node : public Expr_Node
{
public:
  Number_Node (int num);
  ~Number_Node (void);

  virtual void accept (Expr_Node_Visitor & v);

private:
  int value_;
};

#endif
