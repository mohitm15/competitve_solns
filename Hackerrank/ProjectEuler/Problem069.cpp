//By Mohit MAroliya


#include <iostream>

int main()
{
 
  const unsigned int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 57 };

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned long long limit;
    std::cin >> limit;

    unsigned long long bestPos = 1;
    for (auto p : primes)
    {
      if (bestPos >= (limit + p - 1) / p)
        break;

      bestPos *= p;
    }

    std::cout << bestPos << std::endl;
  }
  return 0;
}
