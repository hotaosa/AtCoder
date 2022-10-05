#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

  vector<vector<unordered_map<int, long long> > > dp1(n, vector<unordered_map<int, long long> >(n));
  vector<vector<unordered_map<int, long long> > > dp2(n, vector<unordered_map<int, long long> >(n));

  dp1[0][0][a[0][0]] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - i; ++j) {
      if (i > 0) for (auto m : dp1[i - 1][j]) dp1[i][j][m.first ^ a[i][j]] += m.second;
      if (j > 0) for (auto m : dp1[i][j - 1]) dp1[i][j][m.first ^ a[i][j]] += m.second;
    }
  }

  dp2[n - 1][n - 1][a[n - 1][n - 1]] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= n - 1 - i; --j) {
      if (i < n - 1) for (auto m : dp2[i + 1][j]) dp2[i][j][m.first ^ a[i][j]] += m.second;
      if (j < n - 1) for (auto m : dp2[i][j + 1]) dp2[i][j][m.first ^ a[i][j]] += m.second;
    }
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int j = n - 1 - i;
    for (auto m : dp1[i][j]) res += m.second * dp2[i][j][m.first ^ a[i][j]];
  }

  cout << res << endl;  
  return 0;
}
