#include <cmath>
#include <iostream>

// return length of period or 0 for perfect squares
unsigned int getPeriodLength(unsigned int x)
{
  // without any fractional part yet ...
  unsigned int root = sqrt(x);

  // exclude perfect squares (no period)
  if (root * root == x)
    return 0;

  // the integer part of sqrt(x)
  unsigned int a = root;
  // let's use a variable numerator to store what we subtract
  unsigned int numerator   = 0; // initially zero, e.g. 4 will appear in second iteration of sqrt(23)
  unsigned int denominator = 1; // initially one,  e.g. 7 will appear in second iteration of sqrt(23)

  // count how long it takes until the next period starts
  unsigned int period = 0;

  // terminate when we see the same triplet (a, numerator, denominator) a second time
  // to me it wasn't obvious that this happens exactly when a == 2 * root
  // but thanks to Wikipedia for that trick ...
  while (a != 2 * root)
  {
    numerator   = denominator * a - numerator;
    // must be integer divisions !
    denominator = (x - numerator * numerator) / denominator;
    a           = (root + numerator) / denominator;

    period++;
  }

  return period;
}

int main()
{
  unsigned int last;
  std::cin >> last;

  // count all odd periods
  unsigned int numOdd = 0;
  for (unsigned int i = 2; i <= last; i++) // 0 and 1 are perfect squares
  {
    unsigned int period = getPeriodLength(i);
    // count number of odd lengths (if not a perfect square)
    if (period % 2 == 1)
      numOdd++;
    // branchless: numOdd += period & 1;
  }

  // print result
  std::cout << numOdd << std::endl;

  return 0;
}
