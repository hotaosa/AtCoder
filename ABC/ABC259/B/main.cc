#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double a, b, d;
  cin >> a >> b >> d;
  double rad = d / 180.0 * M_PI;
  printf("%.10f %.10f\n", a * cos(rad) - b * sin(rad), a * sin(rad) + b * cos(rad));
  return 0;
}
