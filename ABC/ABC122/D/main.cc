#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;  
    
  vector<map<string, mint> > dp(n + 1);
  dp[0]["TTT"] = 1;
  for (int i = 0; i < n; ++i) {
    for (auto m : dp[i]) {
      string pre = m.first;
      dp[i + 1][pre.substr(1, 2) + 'A'] += m.second;      
      dp[i + 1][pre.substr(1, 2) + 'T'] += m.second;
      if (pre.substr(1, 2) != "AC") dp[i + 1][pre.substr(1, 2) + 'G'] += m.second;
      if (pre[0] == 'A' && pre[1] == 'G') continue;
      if (pre[0] == 'A' && pre[2] == 'G') continue;
      if (pre[1] == 'A' && pre[2] == 'G') continue;
      if (pre[1] == 'G' && pre[2] == 'A') continue;
      dp[i + 1][pre.substr(1, 2) + 'C'] += m.second;
    }
  }

  mint res = 0;
  for (auto m : dp[n]) res += m.second;
  cout << res.val() << endl;
  return 0;
}
