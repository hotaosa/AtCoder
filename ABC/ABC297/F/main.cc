#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) { long long in; is >> in; m = in; return is; }
ostream &operator<<(ostream &os, const mint &m) { os << m.val(); return os; }

class Binomial {
 public:
  Binomial(const int &size) : size_(size), fact_(size), fact_inv_(size) {
    Initialize();
  }
  mint Factorial(const int &n) const {
    assert(n < size_);
    return fact_[n];
  }
  mint Permutation(const int &n, const int &r) const {
    if (n >= size_) {
      cerr << "Binomial : size error." << endl;
      return mint(0);
    }
    if (n < 0 || r < 0 || n < r) return mint(0);
    return fact_[n] * fact_inv_[n - r];
  }
  mint Combination(const int &n, const int &r) const {
    return Permutation(n, r) * fact_inv_[r];
  }
  mint Homogeneous(const int &n, const int &r) const {
    return Combination(n + r - 1, r);
  }

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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int h, w, k;
  cin >> h >> w >> k;
  Binomial binom(h * w + 1);

  auto Count = [&](int r, int c) -> mint {
    mint ret = 0;
    for (int b = 0; b < (1 << 4); ++b) {
      int rr = r, cc = c;
      for (int i = 0; i < 2; ++i) if (b >> i & 1) --rr;
      for (int i = 2; i < 4; ++i) if (b >> i & 1) --cc;
      if (rr > 0 && cc > 0) {
        ret += binom.Combination(rr * cc, k) * (__builtin_popcount(b) & 1 ? -1 : 1);
      }
    }
    return ret;
  };

  mint res = 0;
  for (int r = 1; r <= h; ++r) {
    for (int c = 1; c <= w; ++c) {
      res += Count(r, c) * r * c * (h - r + 1) * (w - c + 1);
    }
  }
  res /= binom.Combination(h * w, k);
  cout << res << endl;
  return 0;
}
