#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

class Timer {
 public:
  Timer(const double time_limit) : time_limit_(time_limit), time_start_(chrono::system_clock::now()) { }
  inline bool Exceeded() { return ElapsedTime() > time_limit_; }

 private:
  const double time_limit_;
  const chrono::system_clock::time_point time_start_;
  inline double ElapsedTime() {
    auto time_now = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(time_now - time_start_).count();
  }
};

class XorShift {
 public:
  XorShift() : x_(123456789), y_(362436069), z_(521288629), w_(88675123), t_(1) { }
  int Rand() {
    t_ = x_ ^ (x_ << 11);
    x_ = y_; y_ = z_; z_ = w_;
    w_ = (w_ ^ (w_ >> 19)) ^ (t_ ^ (t_ >> 8));
    return w_ & ((1 << 30) - 1);
  }
  int Rand(const int &lb, const int &ub) {
    return Rand() % (ub - lb) + lb;
  }
  double RandDouble() {
    return (double)Rand() / ((1 << 30) - 1);
  }

 private:
  unsigned int x_, y_, z_, w_, t_;  
};

vector<int> divisor(int n) {
  vector<int> ret;
  if (!(n & 1)) ret.push_back(n / 2);
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (n / i != i) ret.push_back(n / i);
    }
  }
  return ret;
}

int main() {
  Timer timer(1950);
  XorShift random;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  auto judge = [&](int k) -> bool {
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (++mp[a[i] % k] == n / 2 + 1) return true;
    }
    return false;
  };

  set<int> se1, se2;
  while (!timer.Exceeded()) {
    int i = random.Rand(0, n - 1);
    int j = random.Rand(i + 1, n);
    int diff = abs(a[i] - a[j]);
    if (!se1.insert(diff).second) continue;
    auto div = divisor(diff);
    for (auto d : div) {      
      if (timer.Exceeded()) break;
      if (d < 3) continue;
      if (se2.insert(d).second && judge(d)) {
        cout << d << endl;
        return 0;
      }
    }
  }

  cout << "-1" << endl;
  return 0;
}
