#include <iostream>

int main() {
  double xa, ya, xb, yb, xc, yc;
  std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
  xb -= xa;
  xc -= xa;
  yb -= ya;
  yc -= ya;

  printf("%.5f\n", std::abs(xb * yc - xc * yb) / 2);
  return 0;
}
