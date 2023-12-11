#include "Calculator.h"

//
// Calculator
//
Calculator::Calculator (void)
{

}

//
// ~Calculator
//
Calculator::~Calculator (void)
{

}

//
// execute
//
void Calculator::execute (void)
{
  std::string infix = get_equation();

  while (infix != "QUIT") {
    Expr_Evaluator_Strategy * strat = preprocess(infix);
    if (strat->parse_expression(infix))
      strat->evaluate_expression();

    infix = get_equation();
  }
}

//
// get_equation
//
std::string Calculator::get_equation (void)
{
  std::string equation;
  std::cout << "Enter an expression in the form '( 5 + 7 ) / 6': ";
  std::getline(std::cin, equation);
  return equation;
}

Expr_Evaluator_Strategy * Calculator::preprocess (std::string & expr)
{
  bool use_postfix = false;

  if (use_postfix)
    return new Postfix_Evaluator_Strategy();
  else
    return new ExprTree_Evaluator_Strategy();
}
