#include <iostream>

double dot(double x, double y, double x1, double y1, double x2, double y2)
{
  return (y2 - y1)*(x - x1) + (x1 - x2)*(y - y1);
}

// return true if point (x,y) is inside the triangle (x1,y1),(x2,y2),(x3,y3)
// uses dot-product
bool isInside(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3)
{
  bool sign1 = dot(x,y, x1,y1, x2,y2) >= 0;
  bool sign2 = dot(x,y, x2,y2, x3,y3) >= 0;
  bool sign3 = dot(x,y, x3,y3, x1,y1) >= 0;

  return (sign1 == sign2) && (sign2 == sign3);
}

// same as above but based on barycentric coordinates
bool isInside2(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3)
{
  double denominator = (y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3);

  double a = ((y2 - y3)*(x - x3) + (x3 - x2)*(y - y3)) / denominator;
  double b = ((y3 - y1)*(x - x3) + (x1 - x3)*(y - y3)) / denominator;
  double c = 1 - a - b;

  return 0 <= a && a <= 1 &&
         0 <= b && b <= 1 &&
         0 <= c && c <= 1;
}

int main()
{
  // number of triangles where the origin is inside
  unsigned int numInside = 0;

  unsigned int tests = 1000;
#ifndef ORIGINAL
  std::cin >> tests;
#endif

  while (tests--)
  {
    int x1,y1,x2,y2,x3,y3;

#ifdef ORIGINAL
    // numbers in CSV format
    char comma;
    std::cin >> x1 >> comma >> y1 >> comma >> x2 >> comma >> y2 >> comma >> x3 >> comma >> y3;
#else
    // numbers separated by spaces
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
#endif

    // both algorithms return the same results
    if (isInside(0,0, x1,y1, x2,y2, x3,y3))
      numInside++;
    //if (isInside2(0,0, x1,y1, x2,y2, x3,y3))
    //  numInside++;
  }

  std::cout << numInside << std::endl;
  return 0;
}
