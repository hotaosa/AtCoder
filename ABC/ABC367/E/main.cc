#include <iostream>
#include <vector>

class Doubling {
 public:
  explicit Doubling(const std::vector<int> &nx, long long max_k = 1LL << 60) {
    std::size_t n = std::size(nx);
    std::size_t logk = 1;
    while ((1LL << logk) <= max_k) ++logk;

    db_ = std::vector(logk, std::vector<int>(n, -1));
    db_[0] = nx;

    for (std::size_t i = 0; i < logk - 1; ++i) {
      for (std::size_t j = 0; j < n; ++j) {
        db_[i + 1][j] = db_[i][db_[i][j]];
      }
    }
  }

  int KthNext(int v, long long k) const {
    for (std::size_t i = 0; k > 0; ++i) {
      if (k & 1) {
        v = db_[i][v];
      }
      k >>= 1;
    }
    return v;
  }

 private:
  std::vector<std::vector<int>> db_;
};

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::vector<int> x(n), a(n);
  for (auto &e : x) {
    std::cin >> e;
    --e;
  }
  for (auto &e : a) {
    std::cin >> e;
  }

  Doubling db(x, k);
  for (int i = 0; i < n; ++i) {
    std::cout << a[db.KthNext(i, k)] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}