#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  int n = h * w;

  vector<bool> is_white(n);
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_white[i * w + j] = s[j] == '.';
  }

  auto shift = [&](int bit) -> int {
    return (bit & ((1 << (w + 1)) - 1)) << 1;
  };

  auto can_put = [&](int v, int bit) -> bool {
    if (!is_white[v]) return false;
    if (v / w > 0 && bit & (1 << w)) return false;
    if (v % w > 0 && bit & 2) return false;
    if (v % w > 0 && bit & (1 << (w + 1))) return false;
    if (v % w < w - 1 && bit & (1 << (w - 1))) return false;
    return true;
  };

  vector<vector<int> > state(n);
  auto dfs = [&](auto dfs, int v, int bit) -> void {
    if (!state[v].empty() && bit <= state[v].back()) return;
    state[v].push_back(bit);
    if (v == n - 1) return;
    int nx = shift(bit);    
    dfs(dfs, v + 1, nx);
    if (can_put(v + 1, nx + 1)) dfs(dfs, v + 1, nx + 1);
  };
  
  dfs(dfs, 0, 0);
  if (is_white[0]) dfs(dfs, 0, 1);

  vector<vector<mint> > dp(n);
  dp[0].assign(2, 1);
  if (!is_white[0]) dp[0][1] = 0;  
  for (int i = 0; i < n - 1; ++i) {
    dp[i + 1].assign(state[i + 1].size(), 0);
    for (int j = 0; j < (int)state[i].size(); ++j) {
      int bit = state[i][j];
      int nx = shift(bit);      
      int id = lower_bound(state[i + 1].begin(), state[i + 1].end(), nx) - state[i + 1].begin();
      dp[i + 1][id] += dp[i][j];      
      if (can_put(i + 1, nx + 1)) dp[i + 1][id + 1] += dp[i][j];
    }
  }

  mint res = 0;
  for (auto r : dp[n - 1]) res += r;
  cout << res.val() << endl;
  return 0;
}
