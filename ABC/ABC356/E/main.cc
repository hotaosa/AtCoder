#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template <class T>
vector<T> CumulativeSumVector(const vector<T> &v, bool pre_zero = false) {
  vector<T> ret;
  if (pre_zero) ret.emplace_back(0);
  for (const T &x : v) ret.emplace_back(ret.empty() ? x : ret.back() + x);
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  int siz = *max_element(begin(a), end(a)) + 1;
  vector<ll> cnt(siz * 2, 0);
  for (auto x : a) {
    ++cnt[x];
  }
  auto sum = CumulativeSumVector(cnt);

  ll res = 0;
  for (int x = 1; x < siz; ++x) {
    if (cnt[x] == 0) continue;
    for (int k = 1; k * x < siz; ++k) {
      int l = x * k - 1;
      int r = x * (k + 1) - 1;
      res += cnt[x] * k * (sum[r] - sum[l]);
    }
    res -= cnt[x] * (cnt[x] + 1) / 2;
  }

  cout << res << endl;
  return 0;
}