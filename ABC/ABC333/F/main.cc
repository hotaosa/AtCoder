#include <iostream>
#include <vector>

#include <atcoder/modint>

using mint = atcoder::modint998244353;
std::istream &operator>>(std::istream &is, mint &m) { long long in; is >> in; m = in; return is; }
std::ostream &operator<<(std::ostream &os, const mint &m) { os << m.val(); return os; }

int main() {
  int n;
  std::cin >> n;

  std::vector<mint> dp(1, 1);
  for (int i = 2; i <= n; ++i) {
    std::vector<mint> d(i, 0), p(i);
    std::swap(d, dp);
    p[0] = mint(2).pow(i - 1) * (mint(2).pow(i) - 1).inv();
    for (int j = 1; j < i; ++j) {
      p[j] = p[j - 1] * mint(2).inv();
      dp[0] += p[j] * d[i - 1 - j];
    }
    for (int j = 1; j < i; ++j) {
      dp[j] = (dp[j - 1] - d[j - 1] * p.back()) * mint(2).inv() + d[j - 1] * p[0];
    }
  }

  for (auto d : dp) std::cout << d << " ";
  std::cout << std::endl;
  return 0;
}