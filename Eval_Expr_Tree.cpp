#include "Eval_Expr_Tree.h"

//
// Eval_Expr_Tree
//
Eval_Expr_Tree::Eval_Expr_Tree (void)
  : result_ (0)
{

}

//
// ~Eval_Expr_Tree
//
Eval_Expr_Tree::~Eval_Expr_Tree (void)
{

}

//
// Visit_Add_Node
//
int Eval_Expr_Tree::Visit_Add_Node (const Add_Node & node)
{
  return node.get_left_child()-> accept(*this) + node.get_right_child()-> accept(*this); 
}

//
// Visit_Divide_Node
//
int Eval_Expr_Tree::Visit_Divide_Node (const Divide_Node & node)
{
  try {
    if (node.get_right_child()->accept(*this) == 0)
      throw division_by_zero_exception();
    return node.get_left_child()-> accept(*this) / node.get_right_child()-> accept(*this);
  }
  catch (division_by_zero_exception e) {
    std::cout << "INVALID EXPRESSION, DIVISION BY ZERO; RESULT WILL BE INCORRECT." << std::endl;
    return 0;
  } 
}

//
// Visit_Modulo_Node
//
int Eval_Expr_Tree::Visit_Modulo_Node (const Modulo_Node & node)
{
  return node.get_left_child()-> accept(*this) % node.get_right_child()-> accept(*this); 
}

//
// Visit_Multiply_Node
//
int Eval_Expr_Tree::Visit_Multiply_Node (const Multiply_Node & node)
{
  return node.get_left_child()-> accept(*this) * node.get_right_child()-> accept(*this); 
}

//
// Visit_Number_Node
//
int Eval_Expr_Tree::Visit_Number_Node (const Number_Node & node)
{
  return node.get_value();
}

//
// Visit_Subtract_Node
//
int Eval_Expr_Tree::Visit_Subtract_Node (const Subtract_Node & node)
{
  return node.get_left_child()-> accept(*this) - node.get_right_child()-> accept(*this); 
}
