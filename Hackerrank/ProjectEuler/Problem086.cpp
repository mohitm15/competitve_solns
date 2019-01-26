//By MOhit Maroliya


#include <cmath>
#include <vector>
#include <iostream>


// how many combinations a,b,c exist for b_c = b + c
unsigned int combinations(unsigned int a, unsigned int b_c)
{
  
  if (2*a < b_c)
    return 0;


  if (a >= b_c)
    return b_c / 2;

  return a - (b_c - 1) / 2; // b+c minus one because b = c is not rejected
}

// count how many paths exists with length a (mediocre speed)
unsigned long long countSingle(unsigned int a)
{
  unsigned long long sum = 0;

  for (unsigned int b_c = 1; b_c <= 2 * a; b_c++)
  {
    // triangle with right angle ?
    auto diagonalSquared = a * a + b_c * b_c;
    unsigned int root = sqrt(diagonalSquared);
    // diagionalSquared needs to be a perfect square
    if (root * root == diagonalSquared)
      sum += combinations(a, b_c);
  }

  return sum;
}

// greatest common divisor
unsigned int gcd(unsigned int x, unsigned int y)
{
  while (x != 0)
  {
    auto temp = x;
    x = y % x;
    y = temp;
  }
  return y;
}

// count combinations per path length
std::vector<unsigned long long> countAll(unsigned int limit)
{
  // result
  std::vector<unsigned long long> solutions(limit + 1, 0);

  // find basic Pythagorean triples
  for (unsigned int m = 1; m <= sqrt(2*limit); m++)
    for (unsigned int n = 1; n < m; n++)
    {
      if (m % 2 == n % 2) // if the inner loop is (n = (m%2)+1; n < m; n += 2)
        continue;         // then this check could be removed
      if (gcd(m, n) != 1)
        continue;

      // two sides
      auto x = m*m - n*n;
      auto y = 2*m*n;
      //auto z = m*m + n*n;

      // ... and now scan all multiples
      for (unsigned int k = 1; k*x <= limit; k++)
        solutions[k*x] += combinations(k*x, k*y);
      for (unsigned int k = 1; k*y <= limit; k++)
        solutions[k*y] += combinations(k*y, k*x);
    }

  return solutions;
}

int main()
{
//#define ORIGINAL
#ifdef ORIGINAL
  unsigned int sum = 0;
  unsigned int a   = 0;
  // until exceeding one million
  while (sum <= 1000000)
    sum += countSingle(++a);

  // print result
  std::cout << a << std::endl;

#else

  // count combinations per path length
  auto solutions = countAll(1000000);

  // compute sum of all path lengths
  std::vector<unsigned long long> total;
  unsigned long long sum = 0;
  for (auto i : solutions)
  {
    sum += i;
    total.push_back(sum);
  }

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int maxA;
    std::cin >> maxA;
    // simple lookup
    std::cout << total[maxA] << std::endl;
  }
#endif

  return 0;
}
