#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

struct MatchNumber {
  int cnt;
  vector<int> nums;
  MatchNumber() : cnt(0), nums(10, 0) { }
  MatchNumber operator+(int x) {
    MatchNumber ret;
    ret.cnt = this->cnt + 1;
    ret.nums = this->nums;
    ++ret.nums[x];
    return ret;
  }
  bool operator<(const MatchNumber &other) const {
    if (cnt != other.cnt) return cnt < other.cnt;
    for (int i = 9; i >= 0; --i) {
      if (nums[i] != other.nums[i]) return nums[i] < other.nums[i];
    }
    return true;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &p : a) cin >> p;

  vector<int> cost = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  vector<MatchNumber> dp(n + 1, MatchNumber());
  for (int i = n; i > 0; --i) {
    if (i < n && dp[i].cnt == 0) continue;
    for (int j = 0; j < m; ++j) {
      if (i - cost[a[j]] >= 0) chmax(dp[i - cost[a[j]]], dp[i] + a[j]);
    }    
  }
  for (int i = 9; i > 0; --i) for (int j = 0; j < dp[0].nums[i]; ++j) cout << i;
  cout << endl;
  return 0;
}
