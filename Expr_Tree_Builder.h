#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"
#include "Add_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"
#include "Multiply_Node.h"
#include "Number_Node.h"
#include "Parenthesis_Node.h"
#include "Subtract_Node.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:
  Expr_Tree_Builder (void);
  virtual ~Expr_Tree_Builder (void);

  virtual void start_expression (void);

  virtual void build_add_operator (void);
  virtual void build_divide_operator (void);
  virtual void build_modulo_operator (void);
  virtual void build_multiply_operator (void);
  virtual void build_number (int n);
  virtual void build_parenthesis (void);
  virtual void build_subtract_operator (void);
  virtual void handle_parenthesis (void);
  void insert_node (Binary_Expr_Node * node);

  Expr_Node * get_expression (void);

private:
  Expr_Node * tree_;
  Stack <Binary_Expr_Node *> initial_stack_;
  Stack <Expr_Node *> final_stack_;
};

#endif
