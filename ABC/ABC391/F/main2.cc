#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using ull = unsigned long long;
using ll = long long;

struct S {
  ll value;
  std::array<int, 3> idx;
  bool operator<(const S &other) const { return value < other.value; }
};

ll Eval(const std::array<std::vector<ll>, 3> &vs,
        const std::array<int, 3> &idx) {
  ll res = 0;
  for (int i = 0; i < 3; ++i) {
    int j = (i + 1) % 3;
    res += vs[i][idx[i]] * vs[j][idx[j]];
  }
  return res;
}

std::array<int, 3> Increment(std::array<int, 3> a, int i) {
  ++a[i];
  return a;
}

struct MakeArrayHash {
  ull operator()(const std::array<int, 3> &a) const {
    ull base = 200000;
    ull hash = 0, b = 0;
    for (int i = 0; i < 3; ++i) {
      hash += a[i] * b;
      b *= base;
    }
    return hash;
  }
};

int main() {
  int n, k;
  std::cin >> n >> k;

  std::array<std::vector<ll>, 3> vs{};
  for (auto &v : vs) {
    v.resize(n);
    for (auto &e : v) std::cin >> e;
    std::sort(std::rbegin(v), std::rend(v));
  }

  std::priority_queue<S, std::vector<S>> pque;
  pque.emplace(Eval(vs, {0, 0, 0}));

  std::unordered_set<std::array<int, 3>, MakeArrayHash> se;

  while (--k) {
    auto s = pque.top();
    pque.pop();
    for (int i = 0; i < 3; ++i) {
      if (s.idx[i] == n - 1) continue;
      auto nidx = Increment(s.idx, i);
      if (se.insert(nidx).second) {
        pque.emplace(S{Eval(vs, nidx), nidx});
      }
    }
  }

  std::cout << pque.top().value << "\n";
  return 0;
}