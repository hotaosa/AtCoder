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
  sort(f.rbegin(), f.rend());

  auto judge = [&](long long m) -> bool {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] * f[i] > m) {
        cnt += ((a[i] * f[i] - m  + f[i] - 1) / f[i]);
      }
    }
    return cnt <= k;
  };

  long long l = -1, r = 1LL << 60;
  while (r - l > 1) {
    long long m = (l + r) / 2LL;
    if (judge(m)) r = m;
    else l = m;
  }
  cout << r << endl;  
  return 0;
}
