// -*- C++ -*-

//==============================================================================
/**
 * @file         Eval_Expr_Tree.h
 */
//==============================================================================

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"
#include "Add_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"
#include "Multiply_Node.h"
#include "Number_Node.h"
#include "Subtract_Node.h"
#include <iostream>
#include <exception>

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:

  /*
   * @class division_by_zero_exception
   *
   * Exception thrown to indicate division by zero.
   */
  class division_by_zero_exception : public std::exception
  {
  public:
    /// Default constructor.
    division_by_zero_exception (void)
      : std::exception () { }
  };

  Eval_Expr_Tree (void);
  virtual ~Eval_Expr_Tree (void);

  virtual int Visit_Add_Node (const Add_Node & node);
  virtual int Visit_Divide_Node (const Divide_Node & node);
  virtual int Visit_Modulo_Node (const Modulo_Node & node);
  virtual int Visit_Multiply_Node (const Multiply_Node & node);
  virtual int Visit_Number_Node (const Number_Node & node);
  virtual int Visit_Subtract_Node (const Subtract_Node & node);

  int result (void) const;

private:
  int result_;
};

#endif
