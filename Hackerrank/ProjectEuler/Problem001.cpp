// By Mohit Maroliya

#include <iostream>

// triangular number: `sum{x}=1+2+..+x = x*(x+1)/2`
unsigned long long sum(unsigned long long x)
{
  return x * (x + 1) / 2;
}

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned long long last;
    std::cin >> last;

    // not including that number
    last--;

    // find sum of all numbers divisible by 3 or 5
    auto sumThree   =  3 * sum(last /  3);
    auto sumFive    =  5 * sum(last /  5);

    // however, those numbers divisible by 3 AND 5 will be counted twice
    auto sumFifteen = 15 * sum(last / 15);

    std::cout << (sumThree + sumFive - sumFifteen) << std::endl;
  }

  return 0;
}
