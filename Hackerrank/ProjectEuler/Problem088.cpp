//By Mohit Maroliya

#include <iostream>
#include <vector>

const unsigned int Limit = 200000; 
// [k] => [size of set]
std::vector<unsigned int> minK(Limit, 9999999); 

// found a better solution with k terms for number n ?
bool valid(unsigned int n, unsigned int k)
{
  // too many terms ? (more than 12000)
  if (k >= minK.size())
    return false;

  // found a smaller number n with the same number of terms k ?
  if (minK[k] > n)
  {
    // note: the default value of minK[] is 9999999
    minK[k] = n;
    return true;
  }

  return false;
}

unsigned int getMinK(unsigned int n, unsigned int product, unsigned int sum,
                     unsigned int depth = 1, unsigned int minFactor = 2)
{

  if (product == 1)
    return valid(n, depth + sum - 1) ? 1 : 0;

  unsigned int result = 0;
  if (depth > 1)
  {
    // perfect match ?
    if (product == sum)
      return valid(n, depth) ? 1 : 0;

    // try to finish sequence
    if (valid(n, depth + sum - product))
      result++;
  }

  // and now all remaining factors
  for (unsigned int i = minFactor; i*i <= product; i++)
    if (product % i == 0) // found a factor ? let's dig deeper ...
      result += getMinK(n, product / i, sum - i, depth + 1, i);

  return result;
}

int main()
{
  unsigned int limit;
  std::cin >> limit;
  minK.resize(limit + 1);

  // k(2) = 4
  unsigned int n = 4;

  // result
  unsigned int sum = 0;

  // 0 and 1 are not used, still 11999 to go ...
  unsigned int todo = limit - 1;
  while (todo > 0)
  {
    // analyze n
    unsigned int found = getMinK(n, n, n);
    // at least one new k(n) found ?
    if (found > 0)
    {
      todo -= found;
      sum  += n;
    }

    // next number
    n++;
  }

  // print result
  std::cout << sum << std::endl;
  return 0;
}
