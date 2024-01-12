#include "Expr_Tree_Builder.h"

//
// Expr_Tree_Builder
//
Expr_Tree_Builder::Expr_Tree_Builder (void)
  : tree_ (nullptr)
{

}

//
// ~Expr_Tree_Builder
//
Expr_Tree_Builder::~Expr_Tree_Builder (void)
{
  delete tree_;
}

//
// start_expression
//
void Expr_Tree_Builder::start_expression (void)
{
  
}

//
// build_add_operator
//
void Expr_Tree_Builder::build_add_operator (void)
{
  Binary_Expr_Node * node = new Add_Node();

  insert_node(node);
}

//
// build_divide_operator
//
void Expr_Tree_Builder::build_divide_operator (void)
{
  Binary_Expr_Node * node = new Divide_Node();

  insert_node(node);
}

//
// build_modulo_operator
//
void Expr_Tree_Builder::build_modulo_operator (void)
{
  Binary_Expr_Node * node = new Modulo_Node();

  insert_node(node);
}

//
// build_multiply_operator
//
void Expr_Tree_Builder::build_multiply_operator (void)
{
  Binary_Expr_Node * node = new Multiply_Node();

  insert_node(node);
}

//
// build_number
//
void Expr_Tree_Builder::build_number (int n)
{
  Expr_Node * node = new Number_Node(n);

  final_stack_.push(node);
}

//
// build_parenthesis
//
void Expr_Tree_Builder::build_parenthesis (void)
{
  Binary_Expr_Node * node = new Parenthesis_Node();

  initial_stack_.push(node);
}

//
// handle_parenthesis
//
void Expr_Tree_Builder::handle_parenthesis (void)
{  
  while ( (!initial_stack_.is_empty()) && (initial_stack_.top()->get_precedence() != 2) ) {
    Binary_Expr_Node * temp = initial_stack_.top();
    initial_stack_.pop();

    temp->set_right_child(final_stack_.top());
    final_stack_.pop();

    temp->set_left_child(final_stack_.top());
    final_stack_.pop();

    final_stack_.push(temp);
  }

  delete initial_stack_.top();
  initial_stack_.pop();
}

//
// build_subtract_operator
//
void Expr_Tree_Builder::build_subtract_operator (void)
{
  Binary_Expr_Node * node = new Subtract_Node();

  insert_node(node);
}

//
// insert_node
//
void Expr_Tree_Builder::insert_node (Binary_Expr_Node * node)
{
  while ( (!initial_stack_.is_empty()) && (initial_stack_.top()->get_precedence() != 2) && (node->get_precedence() <= initial_stack_.top()->get_precedence()) ) {
    Binary_Expr_Node * temp = initial_stack_.top();
    initial_stack_.pop();

    temp->set_right_child(final_stack_.top());
    final_stack_.pop();

    temp->set_left_child(final_stack_.top());
    final_stack_.pop();

    final_stack_.push(temp);
  }

  initial_stack_.push(node);
}

//
// get_expression
//
Expr_Node * Expr_Tree_Builder::get_expression (void)
{
  while (!initial_stack_.is_empty()) {
    Binary_Expr_Node * temp = initial_stack_.top();
    initial_stack_.pop();

    temp->set_right_child(final_stack_.top());
    final_stack_.pop();

    temp->set_left_child(final_stack_.top());
    final_stack_.pop();

    final_stack_.push(temp);   
  }
  
  tree_ = final_stack_.top();
  final_stack_.pop();

  return tree_;
}
