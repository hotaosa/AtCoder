#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

class XorBasis {
 public:
  XorBasis(const vector<long long> &v) : bit_basis_(60, -1) {
    for (auto e: v) {
      for (const auto &b : basis_) e = min(e, e ^ b);
      for (auto &&b : basis_) b = min(b, b ^ e);
      if (e) basis_.push_back(e);
    }
    sort(basis_.begin(), basis_.end());
    rank_ = basis_.size();
    for (int i = 0; i < rank_; ++i) {
      bit_basis_[MSB(basis_[i])] = basis_[i];
    }
  }
  vector<long long> Basis() const { return basis_; }
  long long KthXor(long long k) const {
    assert(k > 0 && k <= (1LL << rank_));
    --k;
    long long ret = 0;
    for (int i = 0; i < 60; ++i) {
      if (k & (1LL << i)) ret ^= basis_[i];
    }
    return ret;
  }
  bool CanMake(long long x) const {
    while (x) {
      auto b = bit_basis_[MSB(x)];
      if (b == -1) return false;      
      x ^= b;
    }
    return true;
  }
 private:
  int MSB(long long x) const {
    if (x == 0) return 0;
    for (int i = 1; i <= 32; i *= 2) x |= (x >> i);
    return __builtin_popcountll(x);
  }
  int rank_;
  vector<long long> basis_;
  vector<long long> bit_basis_;
};

int main() {
  int n;
  long long l, r;
  cin >> n >> l >> r;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  XorBasis xb(a);  
  for (long long i = l; i <= r; ++i) cout << xb.KthXor(i) << " ";
  cout << endl;
  
  return 0;
}
