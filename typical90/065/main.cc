#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

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
  int r, g, b, k, x, y, z;
  cin >> r >> g >> b >> k >> x >> y >> z;

  const int siz = max(r, max(g, b)) + 1;
  Binomial binom(siz);

  const int rl = k - y, gl = k - z, bl = k - x;
  vector<mint> vr(r + 1), vg(g + 1), vb(b + 1);
  for (int i = 0; i <= r; ++i) vr[i] = binom.Combination(r, i);
  for (int i = 0; i <= g; ++i) vg[i] = binom.Combination(g, i);
  for (int i = 0; i <= b; ++i) vb[i] = binom.Combination(b, i);

  vector<mint> p1(r + 1, 0), p2(g + 1, 0);
  for (int i = rl; i <= r; ++i) p1[i] = vr[i];
  for (int i = gl; i <= g; ++i) p2[i] = vg[i];
  const auto p3 = atcoder::convolution(p1, p2);

  mint res = 0;
  for (int i = bl; i <= min(k, b); ++i) {
    res += vb[i] * p3[k - i];
  }

  cout << res.val() << endl;  
  return 0;
}
