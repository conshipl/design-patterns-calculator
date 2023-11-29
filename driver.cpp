/**
 * Still need to do:
 * - comments/run through Doxygen
 * - general cleanup/restructure as needed
 * - error handling
 */

#include "Calculator.h"

int main (int argc, char * argv [])
{
  Calculator * calc = new Calculator();
  calc->execute();
  delete calc;

  return 0;
}
