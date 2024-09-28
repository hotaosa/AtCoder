#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using ll = long long;

class Counter {
 public:
  explicit Counter(const std::vector<ll> &v) : n_(size(v)), v_(v) {
    std::sort(std::begin(v_), std::end(v_));
    acc_ = {0};
    for (ll x : v_) {
      acc_.emplace_back(acc_.back() + x);
    }
  }

  ll TopKthSum(size_t k) const {
    assert(k <= n_);
    if (k == 0) return 0LL;
    return acc_[n_] - acc_[n_ - k];
  }

  ll Sum() const { return TopKthSum(n_); }

  ll KthLargest(size_t k) const {
    assert(k > 0 && k <= n_);
    return v_[n_ - k];
  }

  ll CountNeedForKthToX(size_t k, ll x) const {
    size_t ig = std::distance(std::lower_bound(std::begin(v_), std::end(v_), x),
                              std::end(v_));
    if (ig >= k) return 0LL;
    size_t count = k - ig;
    return x * count - (TopKthSum(k) - TopKthSum(ig));
  }

 private:
  size_t n_;
  std::vector<ll> v_;
  std::vector<ll> acc_;
};

int main() {
  size_t n, m;
  ll k;
  std::cin >> n >> m >> k;

  if (m == n) {
    while (n--) {
      std::cout << '0' << (n ? ' ' : '\n');
    }
    return 0;
  }

  std::vector<ll> a(n);
  for (auto &e : a) std::cin >> e;
  Counter counter(a);
  ll rem = k - counter.Sum();

  std::vector<ll> res(n, -1);
  ll mth = counter.KthLargest(m);
  for (size_t i = 0; i < n; ++i) {
    if (a[i] + rem < mth) continue;
    ll left = -1, right = rem;

    while (right - left > 1LL) {
      ll mid = (left + right) >> 1;
      auto need = counter.CountNeedForKthToX(m + (a[i] >= mth), a[i] + mid + 1);
      need -= (mid + 1) * (a[i] >= mth);
      (need > rem - mid ? right : left) = mid;
    }
    res[i] = right;
  }

  for (size_t i = 0; i < n; ++i) {
    std::cout << res[i] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}