#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

class Binomial {
 public:
  Binomial(const int &size) : size_(size), fact_(size), fact_inv_(size) {
    Initialize();
  }
  mint Permutation(const int &n, const int &r) {
    if (n >= size_) {
      cerr << "Binomial : size error." << endl;
      return mint(0);
    }
    if (n < 0 || r < 0 || n < r) return mint(0);
    return fact_[n] * fact_inv_[n - r];
  }
  mint Combination(const int &n, const int &r) {
    return Permutation(n, r) * fact_inv_[r];
  }
  mint Homogeneous(const int &n, const int &r) {
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
  int n, r;
  cin >> n >> r;
  Binomial binom(n + 1);
  cout << binom.Combination(n, r).val() << endl;  
  return 0;
}
