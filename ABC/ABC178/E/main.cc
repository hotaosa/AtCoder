#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

int main() {
  int n;
  cin >> n;

  long long lx = INF, ly = INF, rx = -INF, ry = -INF;

  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;

    long long x = a + b, y = a - b;
    lx = min(lx, x);
    ly = min(ly, y);
    rx = max(rx, x);
    ry = max(ry, y);
  }

  cout << max(rx - lx, ry - ly) << endl;
  return 0;
}
