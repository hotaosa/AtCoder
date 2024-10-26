#include <iostream>
#include <vector>
//
#include <atcoder/scc.hpp>

class Doubling {
 public:
  explicit Doubling(const std::vector<int> &nx, std::size_t log_max_k = 62)
      : log_max_k_(log_max_k) {
    db_.assign(log_max_k_, std::vector<int>(std::size(nx)));
    db_[0] = nx;
    for (std::size_t i = 1; i < log_max_k_; ++i) {
      for (std::size_t j = 0; j < std::size(nx); ++j) {
        db_[i][j] = db_[i - 1][db_[i - 1][j]];
      }
    }
  }

  int KthNext(int s, long long k) const {
    assert(k >= 0);
    assert(k < (1LL << log_max_k_));
    for (unsigned int i = 0; k > 0; ++i) {
      if (k & 1) {
        s = db_[i][s];
      }
      k >>= 1;
    }
    return s;
  }

 private:
  const std::size_t log_max_k_;
  std::vector<std::vector<int>> db_;
};

inline long long ModPow(long long a, long long n, long long mod) {
  long long ret = 1LL;
  while (n) {
    if (n & 1LL) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  atcoder::scc_graph graph(n);
  std::vector<int> p(n);
  std::vector<int> loop_size(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    graph.add_edge(i, --p[i]);
  }

  for (const auto &group : graph.scc()) {
    for (int v : group) {
      loop_size[v] = std::size(group);
    }
  }

  Doubling db(p);
  for (int i = 0; i < n; ++i) {
    std::cout << db.KthNext(i, ModPow(2, k, loop_size[i])) + 1 << "\n";
  }

  return 0;
}