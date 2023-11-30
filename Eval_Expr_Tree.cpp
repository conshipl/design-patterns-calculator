#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree (void)
  : result_ (0),
    n1_ (0),
    n2_ (0),
    s_ (Stack <int>)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree (void)
{

}

void Eval_Expr_Tree:Visit_Binary_Expr_Node (const Binary_Expr_Node & node)
{
  
  
  n2_ = s_.top();
  s_.pop();

  n1_ = s_.top();
  s_.pop();

}

void Eval_Expr_Tree::Visit_Add_Node (const Add_Node & node)
{
  Visit_Binary_Expr_Node();
}

void Eval_Expr_Tree::Visit_Divide_Node (const Divide_Node & node)
{

}

void Eval_Expr_Tree::Visit_Modulo_Node (const Modulo_Node & node)
{

}

void Eval_Expr_Tree::Visit_Multiply_Node (const Multiply_Node & node)
{

}

void Eval_Expr_Tree::Visit_Number_Node (const Number_Node & node)
{

}

void Eval_Expr_Tree::Visit_Subtract_Node (const Subtract_Node & node)
{

}
