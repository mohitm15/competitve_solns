//By Mohit Maroliya




#include <iostream>
#include <vector>
#include <algorithm>

//#define ORIGINAL

// find digit root of a number
unsigned int digitRoot(unsigned int x)
{
  // taken from https://en.wikipedia.org/wiki/Digital_root
  //return ((x - 1) % 9) + 1;

  // and my original code:
  unsigned int result = 0;
  while (x > 0)
  {
    result += x % 10;
    x      /= 10;
  }

  // repeat again ?
  if (result >= 10)
    result = digitRoot(result);

  return result;
}

int main()
{
  unsigned int limit = 1000000;

#ifndef ORIGINAL
  // read all test cases
  limit = 1;
  unsigned int tests = 1;
  std::cin >> tests;
  std::vector<unsigned int> input(tests);
  for (auto& x : input)
  {
    std::cin >> x;
    if (limit < x)
      limit = x;
  }
#endif

  // step 1: precompute sum(mdrs) for every x

  std::vector<unsigned char> mdrs(limit + 1, 0);

  // digit root without any factorization
  for (unsigned int i = 2; i <= limit; i++)
    mdrs[i] = digitRoot(i);

  // for each number a ...
  for (unsigned int a = 2; a <= limit; a++)
    // ... adjust all its multiples a*b
    for (unsigned int b = 2; a * b <= limit && b <= a; b++)
      // improved ?
      if (mdrs[a * b] < mdrs[a] + mdrs[b])
        mdrs[a * b] = mdrs[a] + mdrs[b];

  // step 2: display result(s)

#ifdef ORIGINAL
  // sum of mdrs(2..limit-1)
  unsigned int sum = 0;
  for (unsigned int i = 2; i < limit; i++)
    sum += mdrs[i];

  std::cout << sum << std::endl;
#else
  // sum of mdrs(2..i) for every 2 <= i <= limit
  // note: unlike the original problem, it is including limit
  std::vector<unsigned int> sums(mdrs.size(), 0);
  for (unsigned int i = 2; i < sums.size(); i++)
    sums[i] = sums[i-1] + mdrs[i];

  // display results
  for (auto x : input)
    std::cout << sums[x] << std::endl;
#endif

  return 0;
}
