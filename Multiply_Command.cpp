#include "Multiply_Command.h"

//
// Multiply_Command
//
Multiply_Command::Multiply_Command (void)
  : Binary_Op_Command (1)
{

}

//
// ~Multiply_Command
//
Multiply_Command::~Multiply_Command (void)
{

}

//
// evaluate
//
int Multiply_Command::evaluate (int n1, int n2) const
{
  return n1 * n2;
}
