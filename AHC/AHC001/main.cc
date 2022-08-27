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
  inline int Rand() {
    t_ = x_ ^ (x_ << 11);
    x_ = y_; y_ = z_; z_ = w_;
    w_ = (w_ ^ (w_ >> 19)) ^ (t_ ^ (t_ >> 8));
    return w_ & ((1 << 30) - 1);
  }
  inline int Rand(const int &lb, const int &ub) {
    return Rand() % (ub - lb) + lb;
  }
  inline double RandDouble() {
    return (double)Rand() / ((1 << 30) - 1);
  }

 private:
  unsigned int x_, y_, z_, w_, t_;  
};

class Add {
 public:
  Add(int xa, int ya, int xb, int yb, int r) : xa_(xa), ya_(ya), xb_(xb), yb_(yb), r_(r) { }
  inline int Area() const { return (xb_ - xa_) * (yb_ - ya_); }
  inline int Diff() const { return max(0, r_ - Area()); }
  inline bool Enough() const { return Area() >= r_; }
  bool Extend(int dir, int value) {
    switch(dir) {
      case(0):
        if (yb_ + value > ub) return false;
        yb_ += value;
        break;
      case(1):
        if (ya_ - value < lb) return false;
        ya_ -= value;
        break;
      case(2):
        if (xb_ + value > ub) return false;
        xb_ += value;
        break;
      case(3):
        if (xa_ - value < lb) return false;
        xa_ -= value;
        break;
      default:
        return false;
        break;
    }
    return true;
  }
  inline int GetXa() const { return xa_; }
  inline int GetYa() const { return ya_; }
  inline int GetXb() const { return xb_; }
  inline int GetYb() const { return yb_; }
  inline bool OverlapWith(const Add &other) {
    if (xa_ >= other.GetXb()) return false;
    if (ya_ >= other.GetYb()) return false;
    if (xb_ <= other.GetXa()) return false;
    if (yb_ <= other.GetYa()) return false;
    return true;
  }
  inline void Print() { cout << xa_ << " " << ya_ << " " << xb_ << " " << yb_ << endl; }
  
 private:
  int xa_, ya_, xb_, yb_, r_, area_;
  static const int lb = 0, ub = 10000;
};

int main() {
  Timer timer(4990);
  XorShift random;

  int n;
  cin >> n;
  vector<Add> adds;
  vector<bool> enough(n, false);
  vector<int> diff(n), sum(n);

  auto UpdateSum = [&]() -> void {
    sum[0] = diff[0];
    for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + diff[i];
  };

  for (int i = 0; i < n; ++i) {
    int x, y, r;
    cin >> x >> y >> r;
    adds.emplace_back(x, y, x + 1, y + 1, r);
    enough[i] = adds[i].Enough();
    diff[i] = adds[i].Diff();
  }
  UpdateSum();

  while (!timer.Exceeded()) {
    int id = lower_bound(sum.begin(), sum.end(), random.Rand(1, sum.back() + 1)) - sum.begin();
    if (enough[id]) continue;
    int dir = random.Rand(0, 4);
    if (!adds[id].Extend(dir, 1)) continue;
    bool overlap = false;
    for (int i = 0; i < n; ++i) {
      if (i == id) continue;
      overlap |= adds[id].OverlapWith(adds[i]);
    }
    if (overlap) {
      adds[id].Extend(dir, -1);
    } else {
      diff[id] = adds[id].Diff();
      UpdateSum();
      enough[id] = adds[id].Enough();
    }
  }
  
  for (int i = 0; i < n; ++i) adds[i].Print();
  return 0;
}
