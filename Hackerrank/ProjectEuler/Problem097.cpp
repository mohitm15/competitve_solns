//By Mohit Maroliya


#include <iostream>
#include <iomanip>

// GCC only !!!
typedef unsigned __int128 BigNum;

//#define ORIGINAL
#ifdef ORIGINAL
const unsigned int Digits = 10;
const BigNum       Modulo = 10000000000ULL;
#else
const unsigned int Digits = 12;
const BigNum       Modulo = 1000000000000ULL;
#endif

// compute the n-th power of a big number (n >= 0)
BigNum powmod(BigNum base, unsigned int exponent, BigNum modulo)
{
  BigNum result = 1;
  while (exponent > 0)
  {
    // fast exponentiation
    if (exponent & 1)
      result = (result * base) % modulo;

    base = (base * base) % modulo;
    exponent >>= 1;
  }
  return result;
}

int main()
{
  unsigned long long sum = 0;

  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
  {
    // read a * b^c + d
    unsigned long long factor, base, exponent, add;
    std::cin >> factor >> base >> exponent >> add;

    // compute result
    unsigned long long result = (powmod(base, exponent, Modulo) * factor + add) % Modulo;

    // modulo all the way ... we need only the last 10 (or 12) digits
    sum += result;
    sum %= Modulo;
  }

  // print with leading zeros
  std::cout << std::setfill('0') << std::setw(Digits) << sum;
  return 0;
}
