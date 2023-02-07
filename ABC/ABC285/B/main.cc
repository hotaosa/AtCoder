#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  s = "0" + s;

  for (int i = 1; i < n; ++i) {
    int res = 0;
    for (int j = 1; i + j <= n; ++j) {
      if (s[j] != s[j + i]) ++res;
      else break;
    }
    cout << res << endl;
  }
  
  return 0;
}
