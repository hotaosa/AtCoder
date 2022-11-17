#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  auto func = [&](int state_x, int state_y) -> long long {
    long long ret = 0;
    for (int i = 0; i < n; ++i) {
      long long xi = x[i], yi = y[i];
      if (state_x == 0) xi = -xi;
      if (state_y == 0) yi = -yi;
      if (xi + yi > 0) ret += xi + yi;
    }
    return ret;
  };

  long long res = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      res = max(res, func(i, j));
    }
  }
  cout << res << endl;  
  return 0;
}
