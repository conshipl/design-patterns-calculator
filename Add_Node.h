// -*- C++ -*-

//==============================================================================
/**
 * @file         Add_Node.h
 */
//==============================================================================

#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

/*
 * @class Add_Node
 */
class Add_Node : public Binary_Expr_Node
{
public:
  /// Default constructor
  Add_Node (void);

  /*
   * Initializing constructor.
   *
   * @param[in]         right          Pointer to right child node
   * @param[in]         left           Pointer to left child node
   */
  Add_Node (Expr_Node * right, Expr_Node * left);

  /// Destructor
  ~Add_Node (void);

  /*
   * Allow Visitor access to Add_Node to perform operations as needed.
   *
   * @param[in]         v              Reference to Visitor object
   */
  virtual int accept (Expr_Node_Visitor & v);
};

#endif
