#include <cassert>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
using ld = long double;

template <class T>
vector<T> CumulativeSumVector(const vector<T> &v, bool pre_zero = false) {
  vector<T> ret;
  if (pre_zero) ret.emplace_back(0);
  for (const T &x : v) ret.emplace_back(ret.empty() ? x : ret.back() + x);
  return ret;
}

template <class T>
class ConvexHullTrick {
 public:
  ConvexHullTrick() = default;
  bool Empty() const { return dq_.empty(); }
  void Clear() { dq_.clear(); }
  void Add(const T &a, const T &b) {
    pair<T, T> line(a, b);
    if (Empty()) {
      dq_.emplace_front(line);
      return;
    }
    if (dq_.front().first <= a) {
      if (dq_.front().first == a) {
        if (dq_.front().second <= b) return;
        dq_.pop_front();
      }
      while (dq_.size() >= 2 && Check(line, dq_[0], dq_[1])) dq_.pop_front();
      dq_.emplace_front(line);
    } else {
      assert(a <= dq_.back().first);
      if (dq_.back().first == a) {
        if (dq_.back().second <= b) return;
        dq_.pop_back();
      }
      while (dq_.size() >= 2 &&
             Check(dq_[dq_.size() - 2], dq_[dq_.size() - 1], line))
        dq_.pop_back();
      dq_.emplace_back(line);
    }
  }
  T Query(const T &x) const {
    assert(!Empty());
    int l = -1, r = dq_.size() - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (GetY(dq_[m], x) >= GetY(dq_[m + 1], x)) {
        l = m;
      } else {
        r = m;
      }
    }
    return GetY(dq_[r], x);
  }
  T QueryInc(const T &x) {
    assert(!Empty());
    while (dq_.size() >= 2 && GetY(dq_[0], x) >= GetY(dq_[1], x))
      dq_.pop_front();
    return GetY(dq_.front(), x);
  }
  T QueryDec(const T &x) {
    assert(!Empty());
    while (dq_.size() >= 2 &&
           GetY(dq_[dq_.size() - 1], x) >= GetY(dq_[dq_.size() - 2], x))
      dq_.pop_back();
    return GetY(dq_.back(), x);
  }
  void Debug() const {
    cerr << "--------------------\n";
    for (auto [f, s] : dq_) {
      cerr << f << " " << s << endl;
    }
    cerr << "--------------------\n";
  }

 private:
  deque<pair<T, T> > dq_;
  int Sign(const T &x) const { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
  bool Check(const pair<T, T> &a, const pair<T, T> &b,
             const pair<T, T> &c) const {
    if (a.second == b.second || b.second == c.second) {
      return Sign(b.first - a.first) * Sign(c.second - b.second) >=
             Sign(c.first - b.first) * Sign(b.second - a.second);
    }
    return (long double)(b.first - a.first) * Sign(c.second - b.second) /
               (long double)(abs(b.second - a.second)) >=
           (long double)(c.first - b.first) * Sign(b.second - a.second) /
               (long double)(abs(c.second - b.second));
  }
  T GetY(const pair<T, T> &a, const T &x) const {
    return a.first * x + a.second;
  }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  vector<ld> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i > 0) {
      a[i] += a[i - 1];
    }
  }

  ConvexHullTrick<ld> cht;

  auto Solve = [&](int i) -> ld {
    ld l = 0, r = 1.01e6;
    while (r - l > 1e-6) {
      ld m = (l + r) / 2.0;
      if (cht.Query(m) <= i * m - a[i]) {
        l = m;
      } else {
        r = m;
      }
    }
    return r;
  };

  vector<ld> res(n);
  cht.Add(n, -a[n]);
  for (int i = n - 1; i >= 0; --i) {
    res[i] = Solve(i);
    cht.Add(i, -a[i]);
  }

  for (auto r : res) {
    cout << r << endl;
  }

  return 0;
}