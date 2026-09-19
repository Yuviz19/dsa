#include <algorithm>
#include <cmath>

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2,
                  int y2) {
  int XClosest = std::max(x1, std::min(xCenter, x2));
  int YClosest = std::max(y1, std::min(yCenter, y2));

  // if cx < x1  → closest x = x1
  // if cx > x2  → closest x = x2
  // otherwise   → closest x = cx

  int xDistance = std::pow((XClosest - xCenter), 2);
  int yDistance = std::pow((YClosest - yCenter), 2);

  int z = xDistance + yDistance;

  if (std::pow(z, 0.5) <= radius) {
    return true;
  }

  return false;
}
