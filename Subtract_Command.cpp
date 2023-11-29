#include "Subtract_Command.h"

//
// Subtract_Command
//
Subtract_Command::Subtract_Command (void)
{

}

//
// ~Subtract_Command
//
Subtract_Command::~Subtract_Command (void)
{

}

//
// evaluate
//
int Subtract_Command::evaluate (int n1, int n2) const
{
  return n1 - n2;
}
