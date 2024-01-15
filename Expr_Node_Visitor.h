// -*- C++ -*-

//==============================================================================
/**
 * @file         Expr_Node_Visitor.h
 */
//==============================================================================

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

class Add_Node;
class Divide_Node;
class Modulo_Node;
class Multiply_Node;
class Number_Node;
class Subtract_Node;

/*#include "Add_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"
#include "Multiply_Node.h"
#include "Number_Node.h"
#include "Subtract_Node.h"*/

class Expr_Node_Visitor 
{
public:
  Expr_Node_Visitor (void);
  virtual ~Expr_Node_Visitor (void);

  virtual int Visit_Add_Node (const Add_Node & node) = 0;
  virtual int Visit_Divide_Node (const Divide_Node & node) = 0;
  virtual int Visit_Modulo_Node (const Modulo_Node & node) = 0;
  virtual int Visit_Multiply_Node (const Multiply_Node & node) = 0;
  virtual int Visit_Number_Node (const Number_Node & node) = 0;
  virtual int Visit_Subtract_Node (const Subtract_Node & node) = 0;
};

#endif
