#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  vector<string> s(8);
  for (auto &p : s) cin >> p;

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (s[i][j] == '*') {
        cout << char('a' + j) << 8 - i << endl;
      }
    }
  }
  
  return 0;
}
