#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;

  double win_p = 0.;
  for (int i = 1; i <= n; ++i) {
    int num = i;
    double p = 1. / n;
    while (num < k) {
      num *= 2;
      p /= 2.;
    }
    win_p += p;
  }

  printf("%.10f\n", win_p);
  return 0;
}
