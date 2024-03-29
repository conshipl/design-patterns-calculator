// -*- C++ -*-

//==============================================================================
/**
 * @file         Multiply_Node.h
 */
//==============================================================================

#ifndef _MULTIPLY_NODE_H_
#define _MULTIPLY_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Multiply_Node : public Binary_Expr_Node
{
public:
  Multiply_Node (void);
  Multiply_Node (Expr_Node * right, Expr_Node * left);
  ~Multiply_Node (void);

  virtual int accept (Expr_Node_Visitor & v);
};

#endif
