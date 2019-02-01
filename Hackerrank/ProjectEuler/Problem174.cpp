//By  Mohit Maroliya

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  const unsigned int limit = 1000000;

  // count different layouts for a number of tiles
  std::vector<unsigned int> solutions(limit + 1, 0);

  // start with smallest outer ring
  for (unsigned int outer = 3; ; outer++)
  {
    unsigned int sum = 0;
    // add as many inner rings as possible
    for (unsigned int inner = outer; inner >= 3; inner -= 2)
    {
      // tiles needed to create one ring whose sides are "inner" tiles long
      unsigned int ring = 4 * (inner - 1);

      // runnng out of tiles ?
      if (sum + ring > limit)
        break;

      // add valid ring
      sum += ring;
      solutions[sum]++;
    }

    // no more inner rings possible, abort
    if (sum == 0)
      break;
  }

  // pre-process all possible answers
  std::vector<unsigned int> result(solutions.size());
  unsigned int one2ten = 0;
  for (unsigned int i = 0; i < solutions.size(); i++)
  {
    auto s = solutions[i];
    if (s >= 1 && s <= 10)
      one2ten++;

    result[i] = one2ten;
  }

  // process test cases
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int last = limit;
    std::cin >> last;
    // simple lookup
    std::cout << result[last] << std::endl;
  }

  return 0;
}
