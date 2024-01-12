#include "Postfix_Evaluator_Strategy.h"

//
// Postfix_Evaluator_Strategy
//
Postfix_Evaluator_Strategy::Postfix_Evaluator_Strategy (void)
  : stack_factory_ (new Stack_Expr_Command_Factory(result_))
{

}

//
// Postfix_Evaluator_Strategy
//
Postfix_Evaluator_Strategy::~Postfix_Evaluator_Strategy (void)
{
  delete stack_factory_;
}

//
// parse_expression
//
bool Postfix_Evaluator_Strategy::parse_expression (const std::string & expr)
{
  std::istringstream input(expr);
  std::string token;
  Expr_Command * cmd = 0;
  Stack <Expr_Command *> temp;

  while (!input.eof()) {

    // istringstream auto-delimits by spaces, so negative numbers are handled already
    input >> token;

    if (token == "+")
      cmd = stack_factory_->create_add_command();
    else if (token == "-")
      cmd = stack_factory_->create_subtract_command();
    else if (token == "*")
      cmd = stack_factory_->create_multiply_command();
    else if (token == "/")
      cmd = stack_factory_->create_divide_command();
    else if (token == "%")
      cmd = stack_factory_->create_modulo_command();
    else if (token == "(") {

      // push opening parenthesis onto stack; continue
      cmd = stack_factory_->create_parenthesis_command();
      temp.push(cmd);
      continue;
    }
    else if (token == ")") {
        
      /*
       * Until we reach the opening parenthesis, pop elements off 
       * stack and enqueue; then pop opening parenthesis.
       */    
      while (temp.top()->get_precedence() != 2) {
        postfix_.enqueue(temp.top());
	temp.pop();
      }
      
      temp.pop();
      continue;
    }
    else if (token == " ")
      continue;
    else {
	
      // if token is a number, cast as integer and create a Number_Command, then enqueue
      cmd = stack_factory_->create_number_command(std::stoi(token));
      postfix_.enqueue(cmd);
      continue;
    }

    /*
     * If token is operator, the stack isn't empty, the operator's precedence
     * is less than/equal to the top of the stack's precedence, and the top of
     * the stack isn't a parenthesis; then continually pop elements off of stack
     * and enqueue them until we find an operator with lower precedence.
     */
    while (( !temp.is_empty() ) && ( cmd->get_precedence() <= temp.top()->get_precedence()) && ( temp.top()->get_precedence() != 2 )) {
      postfix_.enqueue(temp.top());
      temp.pop();
    }

    temp.push(cmd);
  }

  // ensure stack has been fully emptied
  while (!temp.is_empty()) {
    postfix_.enqueue(temp.top());
    temp.pop();
  }

  return true;
}

//
// evaluate_expression
//
void Postfix_Evaluator_Strategy::evaluate_expression (void)
{
  while (!postfix_.is_empty()) {
    Expr_Command * cmd = postfix_.dequeue();
    cmd->execute(result_);
      
    // if it's a Number_Command, delete it to avoid mem leaks
    if (cmd->get_precedence() == 9)
      delete cmd;
  }

  // Remaining stack value is answer; display it
  std::cout << "Result: " << result_.top() << "\n" << std::endl;

}

//
// is_valid_expression
//
bool Postfix_Evaluator_Strategy::is_valid_expression (void) const
{
  return true;
}

//
// number_of_operators
//
size_t Postfix_Evaluator_Strategy::number_of_operators (void) const
{
  return 0;
}

//
// number_of_operands
//
size_t Postfix_Evaluator_Strategy::number_of_operands (void) const
{
  return 0;
}
