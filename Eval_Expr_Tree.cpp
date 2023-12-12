#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree (void)
  : result_ (0)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree (void)
{

}

// COMMENT: Do not return a value from the accept () or visit () methods
// in the Visitor pattern. This approach implies that all visit and accept
// methods must return a value, which may not always be the case. Instead,
// accumulate state in the visitor object, and access the state as needed.
//
// REPLY: I understand why my approach would be problematic and bad coding
// practice, but couldn't think of a design change to fix it in time.
int Eval_Expr_Tree::Visit_Add_Node (const Add_Node & node)
{
  return node.get_left_child()-> accept(*this) + node.get_right_child()-> accept(*this); 
}

// COMMENT: Do not return a value from the accept () or visit () methods
// in the Visitor pattern. This approach implies that all visit and accept
// methods must return a value, which may not always be the case. Instead,
// accumulate state in the visitor object, and access the state as needed.
//
// REPLY: I understand why my approach would be problematic and bad coding
// practice, but couldn't think of a design change to fix it in time.
int Eval_Expr_Tree::Visit_Divide_Node (const Divide_Node & node)
{
  return node.get_left_child()-> accept(*this) / node.get_right_child()-> accept(*this); 
}

// COMMENT: Do not return a value from the accept () or visit () methods
// in the Visitor pattern. This approach implies that all visit and accept
// methods must return a value, which may not always be the case. Instead,
// accumulate state in the visitor object, and access the state as needed.
//
// REPLY: I understand why my approach would be problematic and bad coding
// practice, but couldn't think of a design change to fix it in time.
int Eval_Expr_Tree::Visit_Modulo_Node (const Modulo_Node & node)
{
  return node.get_left_child()-> accept(*this) % node.get_right_child()-> accept(*this); 
}

// COMMENT: Do not return a value from the accept () or visit () methods
// in the Visitor pattern. This approach implies that all visit and accept
// methods must return a value, which may not always be the case. Instead,
// accumulate state in the visitor object, and access the state as needed.
//
// REPLY: I understand why my approach would be problematic and bad coding
// practice, but couldn't think of a design change to fix it in time.
int Eval_Expr_Tree::Visit_Multiply_Node (const Multiply_Node & node)
{
  return node.get_left_child()-> accept(*this) * node.get_right_child()-> accept(*this); 
}

// COMMENT: Do not return a value from the accept () or visit () methods
// in the Visitor pattern. This approach implies that all visit and accept
// methods must return a value, which may not always be the case. Instead,
// accumulate state in the visitor object, and access the state as needed.
//
// REPLY: I understand why my approach would be problematic and bad coding
// practice, but couldn't think of a design change to fix it in time.
int Eval_Expr_Tree::Visit_Number_Node (const Number_Node & node)
{
  return node.get_value();
}

// COMMENT: Do not return a value from the accept () or visit () methods
// in the Visitor pattern. This approach implies that all visit and accept
// methods must return a value, which may not always be the case. Instead,
// accumulate state in the visitor object, and access the state as needed.
//
// REPLY: I understand why my approach would be problematic and bad coding
// practice, but couldn't think of a design change to fix it in time.
int Eval_Expr_Tree::Visit_Subtract_Node (const Subtract_Node & node)
{
  return node.get_left_child()-> accept(*this) - node.get_right_child()-> accept(*this); 
}
