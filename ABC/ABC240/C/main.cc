#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<vector<bool> > possible(n + 1, vector<bool>(x + 2, false));
  possible[0][0] = true;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < x; ++j) {
      if (possible[i][j]) {
        possible[i + 1][min(x + 1, j + a)] = true;
        possible[i + 1][min(x + 1, j + b)] = true;
      }
    }
  }
  cout << (possible[n][x] ? "Yes" : "No" ) << endl;
  return 0;
}
