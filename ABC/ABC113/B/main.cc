#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, t, a;
  cin >> n >> t >> a;

  pair<double, int> res = {1e30, -1};
  for (int i = 0; i < n; ++i) {
    double h;
    cin >> h;
    double diff = abs(t - h * 0.006 - a);
    chmin(res, {diff, i + 1});
  }
  cout << res.second << endl;  
  return 0;
}
