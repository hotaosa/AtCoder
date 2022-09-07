#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  vector<long long> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;

  int cnt = 0;
  double res = 0.0;
  do {
    ++cnt;
    double cur = 0;
    for (int i = 1; i < n; ++i) {
      double dx = x[order[i]] - x[order[i - 1]];
      double dy = y[order[i]] - y[order[i - 1]];
      cur += sqrt(dx * dx + dy * dy);
    }
    res += cur;
  } while (next_permutation(order.begin(), order.end()));
  printf("%.10f\n", res / cnt);
  return 0;
}
