#include "Calculator.h"

int main (int argc, char * argv [])
{
  Calculator * calc = new Calculator();
  calc->execute();
  delete calc;

  return 0;
}
