#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

class RollingHash {
 public:
  RollingHash(const string &s, const long long &mod = 1000000007, const long long &base = 10007)
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
  long long Connect(const long long &h1, const long long &h2, const int &len) const {
    return (h1 * power_[len] % mod_ + h2) % mod_;
  }

 private:
  const int size_;
  const long long mod_, base_;
  vector<long long> hashed_, power_;
};

pair<string, int> Solve(const string &t) {
  const int n = t.size() / 2;
  auto r = t;
  reverse(r.begin(), r.end());

  RollingHash rh1(t), rh2(r);
  pair<string, int> ret = {"", -1};

  for (int i = 0; i <= n && ret.first == ""; ++i) {
    const auto h1 = rh1.Connect(rh1.GetHash(0, i), rh1.GetHash(i + n, 2 * n), n - i);
    const auto h2 = rh2.GetHash(n - i, 2 * n - i);
    if (h1 == h2) ret = make_pair(r.substr(n - i, n) + "\n", i);
  }
  return ret;
}

int main() {
  int n;
  string t;
  cin >> n >> t;

  auto res = Solve(t);
  cout << res.first << res.second << endl;
  return 0;
}
