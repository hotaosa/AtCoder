#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

template<class T> inline bool ChangeMax(T &a, const T &b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<long long> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  auto Sum = [&](int len) -> long long {
    long long ret = a[len / 2] * 2;
    if (len & 1) ret += a[(len + 1) / 2] - a[len / 2];
    return ret;
  };

  vector dp(n + 1, vector<long long>(n + 1, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      ChangeMax(dp[i + 1][j], dp[i][j]);
      ChangeMax(dp[i + 1][i + 1], dp[i][j] + Sum(i - j));
    }
  }

  cout << dp[n][n] << endl;
  return 0;
}
