#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
//
#include <atcoder/segtree>

using ll = long long;

constexpr ll INF = 1LL << 60;
struct S {
  ll value;
  size_t idx;
  bool operator<(const S other) const { return value < other.value; }
};
S Max(S a, S b) { return std::max(a, b); }
S Zero() { return S{-INF, 0}; }

class Selector {
 public:
  explicit Selector(const std::vector<ll> &v) : n_(std::size(v)), v_(v) {
    assert(!empty(v_));
    count_ = std::vector<int>(n_, 0);
    seg_ = atcoder::segtree<S, Max, Zero>(n_);
    for (size_t i = 0; i < n_; ++i) {
      seg_.set(i, S{v[i] - 1, i});
    }
  }

  ll SelectNext() {
    S nx = seg_.all_prod();
    ++count_[nx.idx];
    seg_.set(nx.idx, S{v_[nx.idx] - 2 * count_[nx.idx] - 1, nx.idx});
    return nx.value;
  }

 private:
  size_t n_;
  std::vector<ll> v_;
  std::vector<int> count_;
  atcoder::segtree<S, Max, Zero> seg_;
};

void ChangeMax(ll &a, ll b) { a = std::max(a, b); }

int main() {
  size_t n;
  int w;
  std::cin >> n >> w;

  std::vector<std::vector<ll>> items(w + 1);
  for (size_t i = 0; i < n; ++i) {
    int w;
    ll v;
    std::cin >> w >> v;
    items[w].emplace_back(v);
  }

  std::vector<ll> dp(w + 1, -INF);
  dp[0] = 0;

  for (int wi = 1; wi <= w; ++wi) {
    if (std::empty(items[wi])) continue;
    for (int cur = w - wi; cur >= 0; --cur) {
      if (dp[cur] < 0) continue;
      Selector selector(items[wi]);
      for (int nx = cur + wi; nx <= w; nx += wi) {
        ChangeMax(dp[nx], dp[nx - wi] + selector.SelectNext());
      }
    }
  }

  std::cout << *max_element(std::begin(dp), std::end(dp)) << std::endl;
  return 0;
}