//#include "Calculator.h"
#include "Eval_Expr_Tree.h"
#include <iostream>

int main (int argc, char * argv [])
{
  Expr_Node * n1 = new Number_Node(5);
  Expr_Node * n2 = new Number_Node(7);
  Expr_Node * n3 = new Number_Node(6);
  Expr_Node * add = new Add_Node(n2, n1);
  Expr_Node * mult = new Multiply_Node(n3, add);

  Eval_Expr_Tree eval;

  int result = mult-> accept(eval);

  std::cout << "Result: " << result << std::endl;

  return 0;

  /*	
  Calculator * calc = new Calculator();
  calc->execute();
  delete calc;
  */

  return 0;
}
