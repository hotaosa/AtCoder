#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<double> r(n);
  for (int i = 0; i < n; ++i) std::cin >> r[i];
  std::sort(r.begin(), r.end());

  double res = 0.0;
  for (int i = n - k; i < n; ++i) res = (res + r[i]) / 2.0;
  printf("%.10f\n", res);
  return 0;  
}
