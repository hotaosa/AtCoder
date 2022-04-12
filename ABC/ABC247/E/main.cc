#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<int> px(n + 1, n), py(n + 1, n), ple(n + 1, n), pgr(n + 1, n);
  for (int i = n - 1; i >= 0; --i) {
    px[i] = px[i + 1];
    py[i] = py[i + 1];
    ple[i] = ple[i + 1];
    pgr[i] = pgr[i + 1];
    if (a[i] == x) px[i] = i;
    if (a[i] == y) py[i] = i;
    if (a[i] < y) ple[i] = i;
    if (a[i] > x) pgr[i] = i;
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < y || a[i] > x) continue;
    int p1 = max(px[i], py[i]);
    int p2 = min(ple[i], pgr[i]);
    res += max(0, p2 - p1);
  }
  cout << res << endl;
  return 0;
}
