#include "Modulo_Command.h"

//
// Modulo_Command
//
Modulo_Command::Modulo_Command (void)
  : Binary_Op_Command (1)
{

}

//
// ~Modulo_Command
//
Modulo_Command::~Modulo_Command (void)
{

}

//
// evaluate
//
int Modulo_Command::evaluate (int n1, int n2) const
{
  return n1 % n2;
}
