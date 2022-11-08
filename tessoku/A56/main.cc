#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

class RollingHash {
 public:
  RollingHash(const string &s, const long long &mod, const long long &base)
      : size_(static_cast<int>(s.size())), mod_(mod), base_(base) {
    hashed_.assign(size_ + 1, 0);
    power_.assign(size_ + 1, 1);
    for (int i = 0; i < size_; ++i) {
      hashed_[i + 1] = (hashed_[i] * base_ + s[i]) % mod_;
      power_[i + 1] = power_[i] * base_ % mod_;
    }
  }
  long long GetHash(const int &l, const int &r) const {
    return (hashed_[r] - hashed_[l] * power_[r - l] % mod_ + mod_) % mod_;
  }

 private:
  const int size_;
  const long long mod_, base_;
  vector<long long> hashed_, power_;
};

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  RollingHash rh(s, 998244353, 10007);
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;    
    cout << (rh.GetHash(--a, b) == rh.GetHash(--c, d) ? "Yes" : "No") << endl;
  }
  
  return 0;
}
