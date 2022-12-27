#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'o') p[i] |= 1 << j;
    }
  }

  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((p[i] | p[j]) == (1 << m) - 1) ++res;
    }
  }

  cout << res << endl;  
  return 0;
}
