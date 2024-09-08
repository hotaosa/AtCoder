#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  a.insert(end(a), begin(a), end(a));
  for (int i = 1; i < 2 * n; ++i) a[i] += a[i - 1];

  int logk = 0;
  while (1LL << logk <= k) ++logk;

  auto Solve = [&](ll d) -> int {
    vector db(logk, vector<int>(2 * n + 1, 2 * n));
    for (int i = 0; i < 2 * n; ++i) {
      auto it = lower_bound(begin(a), end(a), a[i] + d);
      if (it != end(a)) {
        db[0][i] = it - begin(a);
      }
    }
    for (int i = 0; i < logk - 1; ++i) {
      for (int j = 0; j < 2 * n; ++j) {
        db[i + 1][j] = db[i][db[i][j]];
      }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
      int cur = i, kk = k;
      for (int j = 0; kk > 0; ++j) {
        if (kk & 1) {
          cur = db[j][cur];
        }
        kk >>= 1;
      }
      if (cur <= i + n) ++count;
    }

    return count;
  };

  ll l = 1, r = a[n - 1];
  while (r - l > 1) {
    ll m = (l + r) / 2;
    (Solve(m) ? l : r) = m;
  }

  cout << l << " " << n - Solve(l) << endl;
  return 0;
}
