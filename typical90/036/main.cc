#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}
template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> xd(n), yd(n);
  long long xd_max = -INF, xd_min = INF, yd_max = -INF, yd_min = INF;  

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    xd[i] = x - y;
    yd[i] = x + y;
    chmin(xd_min, xd[i]);
    chmax(xd_max, xd[i]);
    chmin(yd_min, yd[i]);
    chmax(yd_max, yd[i]);
  }

  auto solve = [&](int i) -> long long {
    long long dist = 0;
    chmax(dist, abs(xd[i] - xd_min));
    chmax(dist, abs(xd[i] - xd_max));
    chmax(dist, abs(yd[i] - yd_min));
    chmax(dist, abs(yd[i] - yd_max));
    return dist;
  };    
  
  while (q--) {
    int i;
    cin >> i;    
    cout << solve(--i) << endl;
  }  
  return 0;
}
