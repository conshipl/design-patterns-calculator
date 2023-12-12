// -*- C++ -*-

//==============================================================================
/**
 * @file         Binary_Expr_Node.h
 */
//==============================================================================


#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

/*
 * @class Binary_Expr_Node
 */
class Binary_Expr_Node : public Expr_Node
{
public:
  /// Default constructor
  Binary_Expr_Node (void);

  /*
   * Initializing constructor.
   *
   * @param[in]     precedence     The precedence of the operation
   */      
  Binary_Expr_Node (int precedence);

  /*
   * Initializing constructor.
   *
   * @param[in]     right          Pointer to right child
   * @param[in]     left           Pointer to left child
   */
  Binary_Expr_Node (Expr_Node * right, Expr_Node * left);

  /*
   * Initializing constructor.
   *
   * @param[in]     precedence     The precedence of the operation
   * @param[in]     right          Pointer to right child
   * @param[in]     left           Pointer to left child
   */
  Binary_Expr_Node (int precedence, Expr_Node * right, Expr_Node * left);

  /// Destructor
  virtual ~Binary_Expr_Node (void);
 
  /*
   * Retrieve a pointer to the node's right child.
   *
   * @return        Pointer to right child
   */
  Expr_Node * get_right_child (void) const;

  /*
   * Set the node's right child.
   *
   * @param[in]     node           Pointer to node to set as right child
   */
  void set_right_child (Expr_Node * node);
  
  /*
   * Retrieve a pointer to the node's left child.
   *
   * @return        Pointer to left child
   */ 
  Expr_Node * get_left_child (void) const;

  /*
   * Set the node's left child.
   *
   * @param[in]     node           Pointer to node to set as left child
   */ 
  void set_left_child (Expr_Node * node);

  // Abstract method
  virtual int accept (Expr_Node_Visitor & v) = 0;

protected:
  // Pointer to node's right child
  Expr_Node * right_;

  // Pointer to node's left child
  Expr_Node * left_;
};

#include "Binary_Expr_Node.inl"

#endif
