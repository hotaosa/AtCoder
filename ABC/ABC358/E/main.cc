#include <iostream>
#include <vector>
//
#include <atcoder/modint>

using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) {
  ll in;
  is >> in;
  m = in;
  return is;
}
ostream &operator<<(ostream &os, const mint &m) {
  os << m.val();
  return os;
}

class Binomial {
 public:
  Binomial(int size) : size_(size), fact_(size), fact_inv_(size) {
    Initialize();
  }
  mint Factorial(int n) const {
    assert(n < size_);
    return fact_[n];
  }
  mint Permutation(int n, int r) const {
    if (n >= size_) {
      cerr << "Binomial : size error." << endl;
      return mint(0);
    }
    if (n < 0 || r < 0 || n < r) return mint(0);
    return fact_[n] * fact_inv_[n - r];
  }
  mint Combination(int n, int r) const {
    return Permutation(n, r) * fact_inv_[r];
  }
  mint Homogeneous(int n, int r) const { return Combination(n + r - 1, r); }

 private:
  const int size_;
  vector<mint> fact_, fact_inv_;
  void Initialize() {
    fact_[0] = fact_[1] = fact_inv_[0] = fact_inv_[1] = 1;
    for (int i = 2; i < size_; ++i) fact_[i] = fact_[i - 1] * i;
    fact_inv_[size_ - 1] = fact_[size_ - 1].inv();
    for (int i = size_ - 1; i > 2; --i) fact_inv_[i - 1] = fact_inv_[i] * i;
  }
};

int main() {
  int k;
  cin >> k;
  vector<int> c(26);
  for (auto &e : c) cin >> e;

  Binomial binom(k * 2 + 1);
  vector dp(27, vector<mint>(k + 1, 0));
  dp[0][0] = 1;

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (dp[i][j] == 0) continue;
      dp[i + 1][j] += dp[i][j];
      for (int use = 1; use <= c[i] && j + use <= k; ++use) {
        dp[i + 1][j + use] += dp[i][j] * binom.Combination(j + use, use);
      }
    }
  }

  auto res = accumulate(begin(dp.back()), end(dp.back()), mint(0)) - 1;
  cout << res << endl;
  return 0;
}