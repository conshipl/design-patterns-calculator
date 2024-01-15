// -*- C++ -*-

//==============================================================================
/**
 * @file         Modulo_Node.h
 */
//==============================================================================

#ifndef _MODULO_NODE_H_
#define _MODULO_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Modulo_Node : public Binary_Expr_Node
{
public:
  Modulo_Node (void);
  Modulo_Node (Expr_Node * right, Expr_Node * left);
  ~Modulo_Node (void);

  virtual int accept (Expr_Node_Visitor & v);
};

#endif
