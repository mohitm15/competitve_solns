//By Mohit Maroliya



#include <iostream>
#include <iomanip>

// recursively count solutions
unsigned long long count(unsigned int digits, bool haveAny = false,
  bool haveZero = false, bool haveOne = false, bool haveA = false)
{
  // solved ?
  if (haveZero && haveOne && haveA && digits < 15)
    return 1ULL << (4 * digits); // same as pow(16, digits);

  // processed all digits ? (but no combination of 0, 1, A found)
  if (digits == 0)
    return 0;

  // assume current digit is not 0, 1 or A
  unsigned long long next = count(digits - 1, true, haveZero, haveOne, haveA);
  unsigned long long result = 13 * next;

  // try to use a zero (only allowed if already have any non-zero digit => "no leading zero")
  result += haveZero ? next : count(digits - 1, haveAny, haveAny, haveOne, haveA);
  // try to use 1
  result += haveOne  ? next : count(digits - 1, true, haveZero, true, haveA);
  // try to use A
  result += haveA    ? next : count(digits - 1, true, haveZero, haveOne, true);

#ifndef ORIGINAL
  result %= 1000000007ULL;
#endif

  return result;
}

int main()
{
#ifdef ORIGINAL
  std::cout << std::uppercase << std::hex << count(16) << std::endl;
#else
  unsigned int digits;
  std::cin >> digits;
  std::cout << count(digits) << std::endl;
#endif

  return 0;
}
