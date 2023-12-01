#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Number_Node : public Expr_Node
{
public:
  Number_Node (int num);
  ~Number_Node (void);
  
  int get_value (void) const;
  void set_value (int num);

  virtual int accept (Expr_Node_Visitor & v);

private:
  int value_;
};

#endif
