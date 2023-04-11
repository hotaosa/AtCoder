#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  long long n, m;
  cin >> n >> m;

  long long res = INF;
  for (long long a = 1; a * a <= m + a; ++a) {
    long long b = (m + a - 1) / a;
    if (a <= n && b <= n) {
      res = min(res, a * b);
    }
  }

  cout << (res < INF ? res : -1) << endl;
  return 0;
}
