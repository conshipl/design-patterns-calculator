#include "Calculator.h"

//
// Calculator
//
Calculator::Calculator (void)
{

}

Calculator::Calculator (Expr_Builder * builder)
  : builder_ (builder)
{

}

//
// ~Calculator
//
Calculator::~Calculator (void)
{

}

/*
 * This is garbage code and I fully acknowledge it; need to merge the two executes
 * with Strategy pattern, but probably won't have time tonight, so this seemed 
 * easiest for the moment.
 */
void Calculator::execute_tree (void)
{
  std::string infix = get_equation();

  while (infix != "QUIT") {
    int result = evaluate(infix);

    std::cout << "Result: " << result << std::endl;

    infix = get_equation();
  }
}

//
// execute
//
void Calculator::execute (void)
{
  Stack <int> result;
  Stack_Expr_Command_Factory stack_factory (result);

  Queue <Expr_Command *> postfix;
      
  std::string infix = get_equation();
  
  while (infix != "QUIT") {


    infix_to_postfix(infix, stack_factory, postfix);

    /**
     * Iterate through each Command and execute; chose to pass stack
     * reference that's modified within instead of storing it internally
     * in Stack Factory
     */
    while (!postfix.is_empty()) {
      Expr_Command * cmd = postfix.dequeue();
      cmd->execute(result);
      
      // if it's a Number_Command, delete it to avoid mem leaks
      if (cmd->get_precedence() == 9)
        delete cmd;
    }

    // Remaining stack value is answer; display it
    std::cout << "Result: " << result.top() << "\n" << std::endl;
    
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

//
// infix_to_postfix
//
void Calculator::infix_to_postfix (const std::string & infix, Stack_Expr_Command_Factory & factory, Queue<Expr_Command *> & postfix)
{
  std::istringstream input(infix);
  std::string token;
  Expr_Command * cmd = 0;
  Stack <Expr_Command *> temp;

  while (!input.eof()) {

    // istringstream auto-delimits by spaces, so negative numbers are handled already
    input >> token;

    if (token == "+")
      cmd = factory.create_add_command();
    else if (token == "-")
      cmd = factory.create_subtract_command();
    else if (token == "*")
      cmd = factory.create_multiply_command();
    else if (token == "/")
      cmd = factory.create_divide_command();
    else if (token == "%")
      cmd = factory.create_modulo_command();
    else if (token == "(") {

      // push opening parenthesis onto stack; continue
      cmd = factory.create_parenthesis_command();
      temp.push(cmd);
      continue;
    }
    else if (token == ")") {

        // COMMENT: Create a design that does not require having parenthesis as
        // as command object since parenthesis are not executed.
	//
        // REPLY: A family member has developed an illness and needed a procedure
        // and I've been taking care of them the last three weeks. Between this
        // and hosting Thanksgiving on Thursday, I just don't have the time to 
        // redesign this program, unfortunately.
        //
        // I tried to think through it and come up with an easy/clever solution,
        // but I couldn't think of anything. My possible solution was to change
        // the algorithm a bit so that I could call the infix_to_postfix function
        // recursively, and then when a parenthesis was encountered, it would go
        // into the recursive sub-call and evaluate the inside of the parenthesis
        // first.
        
      /*
       * Until we reach the opening parenthesis, pop elements off 
       * stack and enqueue; then pop opening parenthesis.
       */    
      while (temp.top()->get_precedence() != 2) {
        postfix.enqueue(temp.top());
	temp.pop();
      }

      temp.pop();
      continue;
    }
    else if (token == " ")
      continue;
    else {
	
      // if token is a number, cast as integer and create a Number_Command, then enqueue
      cmd = factory.create_number_command(std::stoi(token));
      postfix.enqueue(cmd);
      continue;
    }

    /*
     * If token is operator, the stack isn't empty, the operator's precedence
     * is less than/equal to the top of the stack's precedence, and the top of
     * the stack isn't a parenthesis; then continually pop elements off of stack
     * and enqueue them until we find an operator with lower precedence.
     */
    while (( !temp.is_empty() ) && ( cmd->get_precedence() <= temp.top()->get_precedence()) && ( temp.top()->get_precedence() != 2 )) {
      postfix.enqueue(temp.top());
      temp.pop();
    }

    temp.push(cmd);
  }

  // ensure stack has been fully emptied
  while (!temp.is_empty()) {
    postfix.enqueue(temp.top());
    temp.pop();
  }
}

bool Calculator::parse_expr (const std::string & infix)
{
  std::istringstream input(infix);
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
    else if (token == " ")
      continue;
    else
      builder_->build_number(std::stoi(token));
  }

  return true;
}

int Calculator::evaluate (const std::string & infix)
{
  /*if (!parse_expr(infix))
    throw std::runtime_exception("Bad expression.");*/

  parse_expr(infix);
  Expr_Node * expr = builder_->get_expression();

  /*if (nullptr == expr.get())
    throw std::runtime_exception("No expression!");*/

  Eval_Expr_Tree eval;
  return expr-> accept(eval);
}
