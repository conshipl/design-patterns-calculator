#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree (void)
  : result_ (0)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree (void)
{

}

int Eval_Expr_Tree::Visit_Add_Node (const Add_Node & node)
{
  return node.get_left_child()-> accept(*this) + node.get_right_child()-> accept(*this); 
}

int Eval_Expr_Tree::Visit_Divide_Node (const Divide_Node & node)
{
  return node.left_-> accept(*this) / node.right_-> accept(*this); 
}

int Eval_Expr_Tree::Visit_Modulo_Node (const Modulo_Node & node)
{
  return node.left_-> accept(*this) % node.right_-> accept(*this); 
}

int Eval_Expr_Tree::Visit_Multiply_Node (const Multiply_Node & node)
{
  return node.left_-> accept(*this) * node.right_-> accept(*this); 
}

int Eval_Expr_Tree::Visit_Number_Node (const Number_Node & node)
{
  return node.value_;
}

int Eval_Expr_Tree::Visit_Subtract_Node (const Subtract_Node & node)
{
  return node.left_-> accept(*this) - node.right_-> accept(*this); 
}
