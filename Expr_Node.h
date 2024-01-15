// -*- C++ -*-

//==============================================================================
/**
 * @file         Expr_Node.h
 */
//==============================================================================

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

class Expr_Node_Visitor;

class Expr_Node 
{
public:
  Expr_Node (void);
  Expr_Node (int precedence);
  virtual ~Expr_Node (void);

  int get_precedence (void);
  virtual int accept (Expr_Node_Visitor & v) = 0;

private:
  int precedence_;
};

#endif
