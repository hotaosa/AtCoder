#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long op(long long a, long long b) {
  return max(a, b);
}
long long e() {
  return -(1LL << 60);
}

using segtree = atcoder::segtree<long long, op, e>;

int main() {
  int w, n;
  cin >> w >> n;

  vector<int> l(n + 1), r(n + 1);
  vector<long long> v(n + 1);
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i] >> v[i];

  vector<segtree> dp(n + 1, segtree(w + 1));
  dp[0].set(0, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      long long cur = dp[i - 1].get(j);
      if (j >= l[i]) {
        cur = max(cur, dp[i - 1].prod(max(0, j - r[i]), j - l[i] + 1) + v[i]);
      }
      dp[i].set(j, cur);
    }
  }

  cout << max(-1LL, dp[n].get(w)) << endl;
  return 0;
}
