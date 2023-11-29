#include "Add_Command.h"

//
// Add_Command
//
Add_Command::Add_Command (void)
{

}

//
// ~Add_Command
//
Add_Command::~Add_Command (void)
{

}

//
// evaluate
//
int Add_Command::evaluate (int n1, int n2) const
{
  return n1 + n2;
}
