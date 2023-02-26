#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int n = t.size();

  string rs = s, rt = t;
  reverse(rs.begin(), rs.end());
  reverse(rt.begin(), rt.end());

  vector<bool> pre(n + 1, false), suf(n + 1, false);
  pre[0] = suf[0] = true;

  for (int i = 0; pre[i] && i < n; ++i) {
    if (s[i] == '?' || t[i] == '?' || s[i] == t[i]) {
      pre[i + 1] = true;
    }
  }

  for (int i = 0; suf[i] && i < n; ++i) {
    if (rs[i] == '?' || rt[i] == '?' || rs[i] == rt[i]) {
      suf[i + 1] = true;
    }
  }

  // for (int i = 0; i <= n; ++i) cerr << (pre[i] ? 1 : 0) << (i == n ? "\n" : "");
  // for (int i = n; i >= 0; --i) cerr << (suf[i] ? 1 : 0) << (i == 0 ? "\n" : "");

  for (int i = 0; i <= n; ++i) {
    cout << (pre[i] && suf[n - i] ? "Yes" : "No" ) << endl;
  }
  
  return 0;
}
