#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T>
class CoordinateCompression {
 public:
  CoordinateCompression() : initialized_(false) { }
  void Add(T x) {
    vec_.push_back(x);
    initialized_ = false;
  }
  int operator()(T x) {
    if (!initialized_) Init();
    if (!order_.count(x)) {      
      return -1;
    }
    return order_[x];
  }
  int operator[](int index) const {
    return vec_[index];
  }
  int Size() {
    if (!initialized_) Init();
    return vec_.size();
  }
 private:
  void Init() {
    sort(vec_.begin(), vec_.end());
    vec_.erase(unique(vec_.begin(), vec_.end()), vec_.end());
    order_.clear();
    for (auto &p : vec_) order_[p] = 0;
    int siz = 0;
    for (auto &p : order_) p.second = siz++;
    initialized_ = true;
  }
  bool initialized_;
  vector<T> vec_;
  map<T, int> order_;
  map<T, int> mp_;
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> y(n), z(n);
  for (auto &p : y) cin >> p;
  for (auto &p : z) cin >> p;

  CoordinateCompression<int> cc;
  cc.Add(0);
  cc.Add(x);
  for (int i = 0; i < n; ++i) {
    cc.Add(y[i]);
    cc.Add(z[i]);
  }
  int siz = cc.Size();

  vector<int> wall(siz, -1);
  for (int i = 0; i < n; ++i) wall[cc(y[i])] = i;
  
  auto dist = [&](int l, int r) {
    return abs(cc[l] - cc[r]);
  };

  const long long INF = 1LL << 60;
  vector<vector<vector<long long> > > dp(2, vector<vector<long long> > (siz, vector<long long>(siz, INF)));  

  int s = cc(0);
  x = cc(x);
  dp[0][s][s] = dp[1][s][s] = 0;

  long long res = INF;
  for (int l = s; l >= 0; --l) {
    for (int r = s; r < siz; ++r) {
      chmin(dp[0][l][r], dp[1][l][r] + dist(l, r));
      chmin(dp[1][l][r], dp[0][l][r] + dist(l, r));
      if (l > 0) {
        int i = wall[l - 1];
        if (i == -1 || (l <= cc(z[i]) && r >= cc(z[i]))) {
          chmin(dp[0][l - 1][r], dp[0][l][r] + dist(l - 1, l));
        }        
      }
      if (r < siz - 1) {
        int i = wall[r + 1];
        if (i == -1 || (l <= cc(z[i]) && r >= cc(z[i]))) {
          chmin(dp[1][l][r + 1], dp[1][l][r] + dist(r, r + 1));
        }        
      }
      if (l <= x && r >= x) {
        chmin(res, dp[0][l][r]);
        chmin(res, dp[1][l][r]);
      }
    }
  }
  cout << (res < INF ? res : -1) << endl;  
  return 0;
}
