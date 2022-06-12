#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());
  vector<long long> sum(n + 1);
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i - 1];

  auto count_op = [&](long long k) -> long long {
    long long res = 0;
    int l = lower_bound(a.begin(), a.end(), k) - a.begin();
    if (l > 0) res += k * l - sum[l];
    int g = a.end() - upper_bound(a.begin(), a.end(), k);
    if (g > 0) res += sum[n] - sum[n - g] - k * g;
    return res;
  };

  while (q--) {
    long long x;
    cin >> x;
    cout << count_op(x) << endl;
  }
  return 0;
}
