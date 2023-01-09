#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

class Point {
 public:
  Point(const long long &pos, const long long &key) : pos_(pos), key_(key) { }
  bool operator<(const Point &other) const { return pos_ < other.pos_; }
  bool KeyIsInside(const Point &l, const Point &r) { return key_ >= l.pos_ && key_ <= r.pos_; }
  long long Dist (const Point &other) const { return abs(pos_ - other.pos_); }

 private:
  long long pos_, key_;
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  long long x;
  cin >> n >> x;

  vector<long long> y(n), z(n);
  for (auto &p : y) cin >> p;
  for (auto &p : z) cin >> p;

  vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    vp.emplace_back(y[i], z[i]);
    vp.emplace_back(z[i], 0);
  }
  vp.emplace_back(0, 0);
  vp.emplace_back(x, 0);
  sort(vp.begin(), vp.end());

  int s = lower_bound(vp.begin(), vp.end(), Point(0, 0)) - vp.begin();
  int g = lower_bound(vp.begin(), vp.end(), Point(x, 0)) - vp.begin();

  n = n * 2 + 2;
  vector dp(n, vector(n, vector<long long>(2, INF)));
  dp[s][s][0] = dp[s][s][1] = 0;

  for (int l = s; l >= 0; --l) {
    for (int r = s; r < n; ++r) {
      if (l > 0 && vp[l - 1].KeyIsInside(vp[l], vp[r])) {
        chmin(dp[l - 1][r][0], dp[l][r][0] + vp[l - 1].Dist(vp[l]));
        chmin(dp[l - 1][r][0], dp[l][r][1] + vp[l - 1].Dist(vp[r]));
      }
      if (r < n - 1 && vp[r + 1].KeyIsInside(vp[l], vp[r])) {
        chmin(dp[l][r + 1][1], dp[l][r][0] + vp[r + 1].Dist(vp[l]));
        chmin(dp[l][r + 1][1], dp[l][r][1] + vp[r + 1].Dist(vp[r]));
      }
    }
  }

  long long res = INF;
  for (int i = 0; i < g; ++i) chmin(res, dp[i][g][1]);
  for (int i = g + 1; i < n; ++i) chmin(res, dp[g][i][0]);

  cout << (res < INF ? res : -1) << endl;
  return 0;
}
