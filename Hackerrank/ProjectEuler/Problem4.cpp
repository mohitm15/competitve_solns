//By Mohit Maroliya


#include <iostream>

// convert 3 digits to a 6 digit palindrome by mirroring and appending these 3 digits
// e.g. 234 becomes 234432
unsigned int makePalindrome(unsigned int x)
{
  unsigned int result = x * 1000;   // abc => abc000
  result +=    x / 100;             // a.. => a..00a
  result +=  ((x / 10) % 10) *  10; // .b. => .b.0b.
  result +=   (x % 10)       * 100; // ..c => ..cc..
  return result;
}

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    // Hackerrank has a variable upper limit (instead of 1000000)
    unsigned int maximum;
    std::cin >> maximum;

    bool found = false;
    // find all palindromes, beginning with the largest
    // walk through all three-digit numbers
    for (auto upper3 = maximum / 1000; upper3 >= 100 && !found; upper3--)
    {
      // "mirror" these three digits to create a six-digit palindrome
      auto palindrome = makePalindrome(upper3);
      // too big ?
      if (palindrome >= maximum)
        continue;

      // split into two factors
      for (unsigned int i = 100; i * i <= palindrome; i++)
        if (palindrome % i == 0) // divisible ?
        {
          // make sure both factors must have three digits
          auto other = palindrome / i;
          if (other < 100 || other > 999)
            continue;

          std::cout << palindrome << std::endl;
          found = true;
          break;
        }
    }
  }
  return 0;
}
