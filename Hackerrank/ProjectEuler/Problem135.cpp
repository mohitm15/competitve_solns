//By Mohit Maroliya


#include <iostream>
#include <vector>

//#define ORIGINAL

int main()
{
#ifdef ORIGINAL
  unsigned int limit = 1000000; // "less than one million"
#else
  unsigned int limit = 8000001; // up to 8 million (inclusive)
#endif

  // precompute solutions
  std::vector<unsigned int> solutions(limit, 0);
  for (unsigned int a = 1; a < limit; a++)
    for (auto b = (a + 3) / 4; b < a; b++)
    {
      auto current = a * (4*b - a);
      if (current >= limit)
        break;

      solutions[current]++;
    }

#ifdef ORIGINAL
  // count all with exactly 10 solutions
  unsigned int count = 0;
  for (auto s : solutions)
    if (s == 10)
      count++;
  std::cout << count << std::endl;

#else

  // look up number of solutions
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int pos;
    std::cin >> pos;
    std::cout << solutions[pos] << std::endl;
  }
#endif

  return 0;
}
