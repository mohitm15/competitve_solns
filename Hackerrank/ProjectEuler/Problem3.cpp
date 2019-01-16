//By Mohit Maroliya


#include <iostream>

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned long long x;
    std::cin >> x;

    // x can be represented by x=factor*otherFactor
    // where factor <= otherFactor
    // therefore factor <= sqrt(x)
    for (unsigned long long factor = 2; factor * factor <= x; factor++)
      // remove factor, actually it's a prime
      // (can occur multiple times, e.g. 20=2*2*5)
      while (x % factor == 0 && x != factor) // note: keep last prime
        x /= factor;

    std::cout << x << std::endl;
  }
  return 0;
}
