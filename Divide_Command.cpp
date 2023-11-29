#include "Divide_Command.h"

//
// Divide_Command
//
Divide_Command::Divide_Command (void)
  : Binary_Op_Command (1)
{

}

//
// ~Divide_Command
//
Divide_Command::~Divide_Command (void)
{

}

//
// evaluate
//
int Divide_Command::evaluate (int n1, int n2) const
{
    // COMMENT: Your code will crash if you have divide by 0.
    //
    // REPLY: Added try-catch to deal with this, though not sure this is the optimal
    // solution. This way, the program doesn't crash and the user is notified.
  try {
    if (n2 == 0)
      throw division_by_zero_exception(); 
    return n1 / n2;
  }
  catch (division_by_zero_exception e) {
    std::cout << "INVALID EXPRESSION, DIVISION BY ZERO; RESULT WILL BE INCORRECT." << std::endl;
    return 0;
  }
}
