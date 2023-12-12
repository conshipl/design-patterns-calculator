// -*- C++ -*-

//==============================================================================
/**
 * @file         Divide_Node.h
 */
//==============================================================================

#ifndef _DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

/*
 * @class Divide_Node
 */
class Divide_Node : public Binary_Expr_Node
{
public:
  /// Default constructor
  Divide_Node (void);

  /*
   * Initializing constructor.
   *
   * @param[in]       right      Pointer to right child node
   * @param[in]       left       Pointer to left child node
   */  
  Divide_Node (Expr_Node * right, Expr_Node * left);

  /// Destructor
  ~Divide_Node (void);

  /*
   * Allow Visitor access to Divide_Node to perform operations as needed.
   *
   * @param[in]       v          Reference to visitor object
   */
  virtual int accept (Expr_Node_Visitor & v);
};

#endif
