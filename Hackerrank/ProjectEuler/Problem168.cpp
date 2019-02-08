

#include <iostream>
unsigned int search(unsigned int numDigits, unsigned int multiplier, unsigned int lastDigit, unsigned int modulo)
{
  // will be 10, 100, 1000, 10000, ...
  unsigned int shift = 10;
  
  unsigned int carry =  0;

  
  unsigned int current = lastDigit;
  unsigned int result  = lastDigit;

  while (--numDigits)
  {
    
    auto next = multiplier * current + carry;
   
    carry     = next / 10;
    
    current   = next % 10;

    if (shift < modulo)
    {
      result += current * shift;
      shift  *= 10;
    }
  }

  
  auto first = multiplier * current + carry;
  
  if (current == 0 || first != lastDigit)
    return 0;

  return result;
}

int main()
{
  unsigned int maxDigits = 100;
  std::cin >> maxDigits;

  const unsigned int Modulo = 100000;

  unsigned int result = 0;

  for (unsigned int numDigits = 2; numDigits <= maxDigits; numDigits++)
   
    for (unsigned int multiplier = 1; multiplier <= 9; multiplier++)
      
      for (unsigned int lastDigit = 1; lastDigit <= 9; lastDigit++)
        result += search(numDigits, multiplier, lastDigit, Modulo);

  std::cout << result % Modulo << std::endl;
  return 0;
}
