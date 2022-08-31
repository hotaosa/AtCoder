#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  auto median = [&](vector<long long> v) -> long long {
    return v[v.size() / 2];
  };

  auto cost = [&](long long xm, long long ym) -> long long {
    long long ret = 0;
    for (int i = 0; i < n; ++i) {
      ret += abs(xm - x[i]);
      ret += abs(ym - y[i]);
    }
    return ret;
  };

  cout << cost(median(x), median(y)) << endl;  
  return 0;
}
