

#include <iostream>
#include <vector>
#include <cmath>

// allowed error, I could probably add a few zeros ...
const double Epsilon = 0.0000001;

// a simple 2D point
struct Point
{
  // create new point
  Point(double x_, double y_)
  : x(x_), y(y_)
  {}

  // return true if two points are identical or very close (allow for error Epsilon)
  bool operator==(const Point& other) const
  {
    return fabs(x - other.x) < Epsilon &&
           fabs(y - other.y) < Epsilon; // faster Manhattan metric, not a true distance
  }

  double x;
  double y;
};

// height in a triangle of size 1
const double Height  = sqrt(3.0) / 2;
// points of the outer-most triangle, the "hull"
// note: below are the values for a size 1 triangle, they will be scaled accordingly in main()
Point A(0,   0);
Point B(1,   0);
Point C(0.5, Height);

// dummy point to indicate that two lines don't intersect (=> they are parallel)
const Point NoIntersection(9999999, 9999999);

// a line described by ax + by = c;
class Line
{
public:
  // create new line through points "from" and "to"
  Line(const Point& from, const Point& to)
  {
    // https://de.wikipedia.org/wiki/Koordinatenform
    a = from.y - to.y;
    b = to.x - from.x;
    c = to.x*from.y - from.x*to.y;
  }

  // return intersection of the current line with a second line
  Point intersect(const Line& other) const
  {
    // Cramer's Rule: https://en.wikipedia.org/wiki/Cramer%27s_rule
    auto determinant = a * other.b - other.a * b;
    // parallel ?
    if (fabs(determinant) < Epsilon)
      return NoIntersection;

    auto x = (c * other.b - other.c * b) / determinant;
    auto y = (a * other.c - other.a * c) / determinant;
    return Point(x, y);
  }

  // return determinant
  double determinant(const Point& p) const
  {
    return a * p.x + b * p.y - c;
  }

private:
  // line parameters
  double a;
  double b;
  double c;
};

// return true if P is inside the triangle ABC
bool insideHull(const Point& p)
{
  // choose anti-clockwise order of points such that points on the inside have a non-negative determinant
  Line bottom  (A, B);
  Line topRight(B, C);
  Line topLeft (C, A);

  // all determinants must have a positive sign (or zero)
  if (bottom  .determinant(p) < -Epsilon) return false;
  if (topRight.determinant(p) < -Epsilon) return false;
  if (topLeft .determinant(p) < -Epsilon) return false;

  // yeah ... found a "good" one :-)
  return true;
}

// return true if the three lines a,b,c create a valid triangle inside the outermost triangle
bool isValidTriangle(const Line& a, const Line& b, const Line& c)
{
  // find intersections of these three lines
  Point ab = a.intersect(b);
  Point bc = b.intersect(c);
  Point ac = a.intersect(c);

  // they must not be parallel
  if (ab == NoIntersection) // note: this case was actually already tested in main()
    return false;
  if (bc == NoIntersection)
    return false;
  if (ac == NoIntersection)
    return false;

  // degenerated case: all lines have the same intersection point
  if (ab == bc) // note: no need to test ab == ac and ac == bc
    return false;

  // intersections points must be inside the outer-most triangle
  return insideHull(ab) && insideHull(bc) && insideHull(ac);
  // insideHull(ab) was already tested in main()
}

int main()
{
  // number of building blocks
  unsigned int size = 36;
  std::cin >> size;

  // middle between A,B and A,C and B,C (of the basic triangle with size=1)
  Point AB((A.x+B.x)/2, (A.y+B.y)/2);
  Point AC((A.x+C.x)/2, (A.y+C.y)/2);
  Point BC((B.x+C.x)/2, (B.y+C.y)/2);

  // create all lines
  std::vector<Line> lines;
  // A-B
  for (unsigned int i = 0; i < size; i++)
    lines.push_back(Line(Point(A.x, i * Height), Point(B.x, i * Height)));
  // A-BC
  for (unsigned int i = 0; i < size; i++)
  {
    lines.push_back(Line(Point(i, A.y), Point(BC.x + i, BC.y)));
    if (i > 0)
      lines.push_back(Line(Point(-(double)i, A.y), Point(BC.x - (double)i, BC.y)));
  }
  // A-C
  for (unsigned int i = 0; i < size; i++)
    lines.push_back(Line(Point(i, A.y), Point(C.x + i, C.y)));
  // B-C
  for (unsigned int i = 0; i < size; i++)
    lines.push_back(Line(Point(i+1, B.y), Point(C.x + i, C.y)));
  // B-AC
  for (unsigned int i = 0; i < 2*size-1; i++)
    lines.push_back(Line(Point(i+1, B.y), Point(AC.x + i, AC.y)));
  // C-AB
  for (unsigned int i = 1; i < 2*size; i++)
    lines.push_back(Line(Point(i * C.x, 0), Point(i * C.x, Height)));

  // resize hull according to user input
  A.x *= size; A.y *= size;
  B.x *= size; B.y *= size;
  C.x *= size; C.y *= size;

  unsigned int count = 0;
  // generate each combination of lines
  for (unsigned int i = 0; i < lines.size(); i++)
    for (unsigned int j = i + 1; j < lines.size(); j++)
    {
      // fast check whether the intersection of two lines results in a valid point
      auto first = lines[i].intersect(lines[j]);
      if (first == NoIntersection || !insideHull(first))
        continue;

      // and the third line ...
      for (unsigned int k = j + 1; k < lines.size(); k++)
        // now we have a potential triangle, check whether it's valid and fully inside the hull
        if (isValidTriangle(lines[i], lines[j], lines[k]))
          count++;
    }

  // display result
  std::cout << count << std::endl;
  return 0;
}
