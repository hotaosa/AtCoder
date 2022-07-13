#include <iostream>
#include <vector>

using namespace std;

long long func(string s) {
  int n = s.length();
  vector<vector<long long> > dp(n + 1, vector<long long>(2, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (j == 4) continue;
      if (j < s[i] - '0') dp[i + 1][1] += dp[i][1] + dp[i][0];
      else if (j > s[i] - '0') dp[i + 1][1] += dp[i][1];
      else { dp[i + 1][1] += dp[i][1]; dp[i + 1][0] += dp[i][0]; }
    }
  }
  return dp[n][0] + dp[n][1];    
}

int main() {
  long long a, b;
  cin >> a >> b;
  string s = to_string(a - 1);
  string t = to_string(b);
  cout << b - a + 1 - (func(t) - func(s)) << endl;
  return 0;
}