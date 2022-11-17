#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> cnt(n, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ++cnt[--a];
    ++cnt[--b];
  }

  pair<int, int> res(-1, -1);
  for (int i = 0; i < n; ++i) chmax(res, {cnt[i], i + 1});
  cout << res.second << endl;  
  return 0;
}
