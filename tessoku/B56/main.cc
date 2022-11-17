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
  string t = s;
  reverse(t.begin(), t.end());

  const long long MOD = 998244353;
  const long long BASE = 100007;
  RollingHash rs(s, MOD, BASE), rt(t, MOD, BASE);

  while (q--) {
    int l1, r1;
    cin >> l1 >> r1;
    int l2 = n - 1 - --r1, r2 = n - 1 - --l1;
    cout << (rs.GetHash(l1, r1) == rt.GetHash(l2, r2) ? "Yes" : "No" ) << endl;
  }
  
  return 0;
}
