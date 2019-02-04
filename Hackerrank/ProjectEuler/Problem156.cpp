//BY Mohit maroliya



#include <iostream>

// decimal => 10
unsigned int base = 10; // change only for modified Hackerrank problem

// count digits in a single number
unsigned int countSingle(unsigned int digit, unsigned long long value)
{
  // actually the problem doesn't ask for zeros, so I could skip this special treatment of zeros ...
  if (value == 0 && digit == 0)
    return 1;

  unsigned int result = 0;
  while (value > 0)
  {
    if (value % base == digit)
      result++;
    value /= base;
  }

  return result;
}

// return f(value, digit)
unsigned long long count(unsigned int digit, unsigned long long value)
{
  // handle a single digit
  if (value < base)
    return value < digit ? 0 : 1;

  // find highest digit
  unsigned long long shift      = 1;
  unsigned long long multiplier = 0;
  while (shift * base <= value)
  {
    shift *= base;
    multiplier++;
  }
  multiplier *= shift / base;

  // split number: "first" represents the left-most digit and "remainder" is everything else
  auto first     = value / shift;
  auto remainder = value % shift;

  // count digit in "remainder"
  auto result = first * multiplier;  // full blocks
  result += count(digit, remainder); // partial block

  // count digit in "first"
  if (digit == first)
    result += remainder + 1;
  if (digit <  first && digit > 0) // I don't need to handle zero, but it felt wrong ...
    result += shift;

  return result;
}

// return sum of all numbers from <= x <= to where count(x, digit) = x
unsigned long long findAll(unsigned int digit, unsigned long long from, unsigned long long to)
{
  // narrowed down to a single number ?
  auto center = (from + to) / 2;
  if (from == center)
  {
    auto current = count(digit, from);
    if (current == from)
      return from;
    else
      return 0;
  }

  unsigned long long result = 0;

  auto countFrom   = count(digit, from);

#define FAST
#ifdef  FAST
  // matches often occur in bunches, try to resolve many at once
  while (countFrom == from && from < to)
  {
    result    += from;
    countFrom += countSingle(digit, ++from);
  }
  if (from >= to + 1)
    return result;
#endif

  center = (from + to) / 2;

  // binary subdivision
  auto countCenter = count(digit, center);
  auto countTo     = count(digit, to);

  // recursive search in lower half
  if (countCenter >= from   && center >= countFrom   && center > from)
    result += findAll(digit, from, center);
  // recursive search in upper half
  if (countTo     >= center && to     >= countCenter && center < to)
    result += findAll(digit, center, to);

  return result;
}

int main()
{
  // 10^12
  const auto Limit = 1000000000000ULL; // actually 80000000001 would suffice
  // will store the result
  unsigned long long sum = 0;

//#define ORIGINAL
#ifdef  ORIGINAL
  for (unsigned int digit = 1; digit < base; digit++)
    sum += findAll(digit, 0, Limit);

#else

  unsigned int tests;
  std::cin >> base >> tests;
  // read all digits and count them
  while (tests--)
  {
    unsigned int digit;
    std::cin >> digit;
    sum += findAll(digit, 0, Limit);
  }
#endif

  // done !
  std::cout << sum << std::endl;
  return 0;
}
