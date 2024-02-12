#include <atcoder/fenwicktree>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template <class T>
class RangeAddPointGet {
 public:
  RangeAddPointGet(const int &size)
      : size_(size), ft_(atcoder::fenwick_tree<T>(size)) {}
  RangeAddPointGet(const vector<T> &v)
      : size_(v.size()), ft_(atcoder::fenwick_tree<T>(v.size())) {
    ft_.add(0, v[0]);
    for (int i = 1; i < size_; ++i) {
      ft_.add(i, v[i] - v[i - 1]);
    }
  }
  T Get(const int &idx) { return ft_.sum(0, idx + 1); }
  void Set(const int &idx, const T &val) { Add(idx, idx + 1, val - Get(idx)); }
  void Add(const int &lidx, const int &ridx, const T &val) {
    ft_.add(lidx, val);
    if (ridx < size_) {
      ft_.add(ridx, -val);
    }
  }
  void PrintAll(const char sep = ' ') {
    for (int i = 0; i < size_; ++i) {
      cout << Get(i) << sep;
    }
    if (sep != '\n') {
      cout << '\n';
    }
  }

 private:
  int size_;
  atcoder::fenwick_tree<T> ft_;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  RangeAddPointGet<ll> seg(a);

  for (int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    auto g = seg.Get(b);
    seg.Set(b, 0);
    if (g >= n) {
      seg.Add(0, n, g / n);
      g %= n;
    }
    if (g) {
      int s = (b + 1) % n;
      int t = (s + g) % n;
      if (s < t) {
        seg.Add(s, t, 1);
      } else {
        seg.Add(s, n, 1);
        seg.Add(0, t, 1);
      }
    }
  }

  seg.PrintAll();
  return 0;
}