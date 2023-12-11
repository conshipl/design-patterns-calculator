#include "ExprTree_Evaluator_Strategy.h"

ExprTree_Evaluator_Strategy::ExprTree_Evaluator_Strategy (void)
  : builder_ (new Expr_Tree_Builder())
{

}

ExprTree_Evaluator_Strategy::~ExprTree_Evaluator_Strategy (void)
{
  delete builder_;
}

bool ExprTree_Evaluator_Strategy::parse_expression (const std::string & expr)
{
  std::istringstream input(expr);
  std::string token;
  
  //builder_.start_expression();

  while (!input.eof()) {
    input >> token;

    if (token == "+")
      builder_->build_add_operator();
    else if (token == "-")
      builder_->build_subtract_operator();
    else if (token == "*")
      builder_->build_multiply_operator();
    else if (token == "/")
      builder_->build_divide_operator();
    else if (token == "%")
      builder_->build_modulo_operator();
    else if (token == "(")
      builder_->build_parenthesis();
    else if (token == ")")
      builder_->handle_parenthesis();
    else if (token == " ")
      continue;
    else
      builder_->build_number(std::stoi(token));
  }

  return true;
}

void ExprTree_Evaluator_Strategy::evaluate_expression (void)
{
  /*if (!parse_expr(infix))
    throw std::runtime_exception("Bad expression.");*/

  Expr_Node * expr = builder_->get_expression();

  /*if (nullptr == expr.get())
    throw std::runtime_exception("No expression!");*/

  Eval_Expr_Tree eval;
  int result = expr-> accept(eval);

  std::cout << "Result: " <<  result << "\n" << std::endl;

}

bool ExprTree_Evaluator_Strategy::is_valid_expression (void) const
{
  return true;
}

size_t ExprTree_Evaluator_Strategy::number_of_operators (void) const
{
  return 0;
}

size_t ExprTree_Evaluator_Strategy::number_of_operands (void) const
{
  return 0;
}
