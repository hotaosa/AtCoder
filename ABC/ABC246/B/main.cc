#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  double r = sqrt(a * a + b * b);
  printf("%.10f %.10f\n", a / r, b / r);
  return 0;
}
