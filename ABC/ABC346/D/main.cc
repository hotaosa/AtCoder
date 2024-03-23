#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void ChangeMin(ll &a, ll b) { a = min(a, b); }

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = s[i] - '0';
  }

  vector<ll> c(n);
  for (auto &e : c) cin >> e;

  constexpr ll INF = 1LL << 60;
  vector dp(2, vector<ll>(2, INF));
  dp[b[0]][0] = 0;
  dp[b[0] ^ 1][0] = c[0];

  for (int i = 1; i < n; ++i) {
    auto d = move(dp);
    dp = vector(2, vector<ll>(2, INF));
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (d[j][k] == INF) continue;
        for (int nj = 0; nj < 2; ++nj) {
          if (nj == j && k) continue;
          auto cost = nj == b[i] ? 0LL : c[i];
          int nk = k | (1 - (nj ^ j));
          ChangeMin(dp[nj][nk], d[j][k] + cost);
        }
      }
    }
  }

  cout << min(dp[0][1], dp[1][1]) << endl;
  return 0;
}