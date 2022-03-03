#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n), f(n);
  for (auto &p : a) cin >> p;
  for (auto &p : f) cin >> p;
  sort(a.begin(), a.end());
  sort(f.begin(), f.end(), greater<>());

  vector<long long> af(n);
  for (int i = 0; i < n; ++i) af[i] = a[i] * f[i];

  auto check = [&](long long m) -> bool {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) cnt += max((af[i] - m + f[i] - 1) / f[i], 0LL);
    return cnt <= k;
  };

  long long l = -1LL, r = 1LL << 60;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (check(m)) r = m;
    else l = m;
  }

  cout << r << endl;
  return 0;
}
