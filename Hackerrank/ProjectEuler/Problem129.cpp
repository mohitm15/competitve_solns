//By Mohit maroliya


#define ORIGINAL

#include <iostream>

// return minimum k where R(k) is divisible by x
unsigned long long getMinK(unsigned long long x)
{
  // same as gcd(x, 10) = 1
  if (x % 5 == 0 || x % 2 == 0)
    return 0;

    unsigned long long result  = 1;
 
  unsigned long long repunit = 1;

  while (repunit != 0)
  {
    // next repunit
    repunit *= 10;
    repunit++;
    // keep it mod divisor
    repunit %= x;

    result++;
  }

  return result;
}

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {

    unsigned long long limit = 1000000;
    std::cin >> limit;
    unsigned long long i = limit;

#ifdef ORIGINAL
    while (getMinK(i) <= limit)
      i++;
    std::cout << i << std::endl;
#else
    std::cout << getMinK(i) << std::endl;
#endif
  }
  return 0;
}
