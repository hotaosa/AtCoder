#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;
  set<string> se;
  int res = -1, mx = -1;
  for (int i = 1; i <= n; ++i) {
    string s;
    int t;
    cin >> s >> t;
    if (se.insert(s).second) if (chmax(mx, t)) res = i;
  }
  cout << res << endl;
  return 0;
}
