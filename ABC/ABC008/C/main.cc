#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) std::cin >> c[i];

  std::vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (c[i] % c[j] == 0) ++cnt[i];
    }
  }

  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < cnt[i]; j += 2) {
      res += 1.0 / (double)cnt[i];      
    }
  }

  printf("%.10f\n", res);
  return 0;
}
