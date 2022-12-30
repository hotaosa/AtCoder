#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;

  vector<double> a(n);
  for (auto &p : a) cin >> p;

  auto judge = [&](double x) -> bool {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += floor(a[i] / x);
    }
    return sum >= k;
  };

  double l = 1.0, r = 1.0e9;
  while (r - l > 5.0e-7) {
    double m = (l + r) / 2.0;
    if (judge(m)) l = m;
    else r = m;
  }

  for (int i = 0; i < n; ++i) {
    cout << floor(a[i] / l) << " ";
  }
  cout << endl;

  return 0;
}
