#include "Calculator.h"

int main (int argc, char * argv [])
{
  /*Expr_Node * n1 = new Number_Node(5);
  Expr_Node * n2 = new Number_Node(7);
  Expr_Node * n3 = new Number_Node(6);
  Expr_Node * add = new Add_Node(n2, n1);
  Expr_Node * mult = new Multiply_Node(n3, add);

  Eval_Expr_Tree eval;

  int result = mult-> accept(eval);

  std::cout << "Result: " << result << std::endl;*/

  Expr_Builder * builder = new Expr_Tree_Builder();
  Calculator * calc = new Calculator(builder);
  calc->execute_tree();
  delete calc;
  delete builder;

  return 0;
}
