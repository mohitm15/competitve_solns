//By Mohit Maroliya



#include <vector>
#include <iostream>
#include <algorithm>

// return true if x is a palindrome
bool isPalindrome(unsigned int x)
{
  auto reduced = x / 10;
  auto reverse = x % 10;
  // fast exit: a trailing zero can't create a palindrome
  if (reverse == 0)
    return false;

  while (reduced > 0)
  {
    // chop off the lowest digit and append it to "reverse"
    reverse *= 10;
    reverse += reduced % 10;
    reduced /= 10;
  }

  // palindrome ? both must be equal
  return reverse == x;
}


int main()
{
  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int limit  = 100000000;
    unsigned int stride = 1; // distance between consecutive square numbers

    std::cin >> limit >> stride;

    std::vector<unsigned int> solutions;
    for (unsigned long long first = 1; 2*first*first < limit; first++)
    {
      auto next = first + stride;
      // sum of a^2 + b^2 + ...
      auto current = first * first + next * next;
      // still within the limit ?
      while (current < limit)
      {
        // check
        if (isPalindrome(current))
          solutions.push_back(current);

        // add one element to the sequence
        next    += stride;
        current += next * next;
      }
    }

    // sort ...
    std::sort(solutions.begin(), solutions.end());
    // .. and remove duplicates
    auto garbage = std::unique(solutions.begin(), solutions.end());
    solutions.erase(garbage, solutions.end());

    // count all solutions
    unsigned long long sum = 0;
    for (auto x : solutions)
      sum += x;

    std::cout << sum << std::endl;
  }

  return 0;
}
