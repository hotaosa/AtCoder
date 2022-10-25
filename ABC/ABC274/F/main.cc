#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

class Fraction {
 public:
  Fraction(const long long &num, const long long &den) : num_(num), den_(den) {
    if (den_ == 0LL) exit(-1);
    const long long g = __gcd(num_, den_);
    if (den_ < 0LL) {
      num_ *= -1;
      den_ *= -1;
    }
    if (g != 1LL) {
      num_ /= g;
      den_ /= g;
    }
  }
  Fraction(const long long &num) : num_(num), den_(1LL) { }
  bool operator==(const Fraction &rhs) const {
    return num_ * rhs.den_ == rhs.num_ * den_;
  }
  bool operator<(const Fraction &rhs) const {
    return num_ * rhs.den_ < rhs.num_ * den_;
  }
  bool operator>(const Fraction &rhs) const {
    return num_ * rhs.den_ > rhs.num_ * den_;
  }
  Fraction operator+(const Fraction &rhs) const {
    const long long g = den_ / __gcd(den_, rhs.den_) * rhs.den_;
    return Fraction(num_ * den_ / g + rhs.num_ * rhs.den_ / g, g);
  }
  Fraction operator-(const Fraction &rhs) const {
    const long long g = den_ / __gcd(den_, rhs.den_) * rhs.den_;
    return Fraction(num_ * den_ / g - rhs.num_ * rhs.den_ / g, g);
  }
  Fraction operator*(const Fraction &rhs) const {
    return Fraction(num_ * rhs.num_, den_ * rhs.den_);
  }
  Fraction operator/(const Fraction &rhs) const {
    if (rhs == Fraction(0LL)) exit(-1);
    return Fraction(num_ * rhs.den_, den_ * rhs.num_);
  }
  long long Num() const { return num_; }
  long long Den() const { return den_; }

 private:
  long long num_, den_;
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, a;
  cin >> n >> a;
  vector<int> w(n), x(n), v(n);
  for (int i = 0; i < n; ++i) cin >> w[i] >> x[i] >> v[i];

  int res = 0;
  for (int i = 0; i < n; ++i) {
    vector<pair<Fraction, int> > vp;
    for (int j = 0; j < n; ++j) {
      if (x[j] >= x[i]) {
        if (x[j] - x[i] <= a) {
          vp.push_back(make_pair(Fraction(0), -w[j]));
          if (v[j] > v[i]) {
            vp.push_back(make_pair(Fraction(a - (x[j] - x[i]), v[j] - v[i]), w[j]));            
          } else if (v[j] < v[i]) {
            vp.push_back(make_pair(Fraction(x[j] - x[i], v[i] - v[j]), w[j]));
          }
        } else if (v[j] < v[i]) {
          vp.push_back(make_pair(Fraction(x[j] - x[i] - a, v[i] - v[j]), -w[j]));
          vp.push_back(make_pair(Fraction(x[j] - x[i], v[i] - v[j]), w[j]));
        }
      } else {
        if (v[j] > v[i]) {
          vp.push_back(make_pair(Fraction(x[i] - x[j], v[j] - v[i]), -w[j]));
          vp.push_back(make_pair(Fraction(x[i] - x[j] + a, v[j] - v[i]), w[j]));
        }
      }
    }
    sort(vp.begin(), vp.end());
    int sum = 0;
    for (auto &p : vp) {
      sum += p.second;
      chmin(res, sum);
    }
  }

  cout << res * (-1) << endl;
  return 0;
}
