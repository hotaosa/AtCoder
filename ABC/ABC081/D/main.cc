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
  vector<int> a(n);
  int ma = -1, pma = -1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (chmax(ma, abs(a[i]))) pma = i;
  }
  
  vector<pair<int, int> > res;
  for (int i = 0; i < n; ++i) {
    if (i != pma) {
      a[i] += a[pma];
      res.push_back({pma + 1, i + 1});
    }
  }

  if (a[pma] > 0) {
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] > a[i + 1]) {
        a[i + 1] += a[i];
        res.push_back({i + 1, i + 2});
      }
    }
  } else {
    for (int i = n - 1; i > 0; --i) {
      if (a[i] < a[i - 1]) {
        a[i - 1] += a[i];
        res.push_back({i + 1, i});
      }
    }
  }

  cout << res.size() << endl;
  for (auto &p : res) cout << p.first << " " << p.second << endl;
  return 0;
}
