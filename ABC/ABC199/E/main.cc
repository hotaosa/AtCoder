#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > cond(n + 1, vector<int>(n, n));
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    chmin(cond[x][y], z);
  }

  vector<long long> dp(1 << n, 0);
  dp[0] = 1;

  vector<int> bits;
  for (int i = 1; i < (1 << n); ++i) bits.push_back(i);
  sort(bits.begin(), bits.end(), [](int i, int j) {
    return __builtin_popcount(i) < __builtin_popcount(j);
  });

  for (auto bit : bits) {
    int pc = __builtin_popcount(bit);
    bool ok = true;
    for (int i = 1; i < n; ++i) ok &= __builtin_popcount(bit & ((1 << i) - 1)) <= cond[pc][i];
    if (!ok) continue;
    for (int i = 0; i < n; ++i) if (bit & (1 << i)) dp[bit] += dp[bit - (1 << i)];    
  }

  cout << dp.back() << endl;  
  return 0;
}
