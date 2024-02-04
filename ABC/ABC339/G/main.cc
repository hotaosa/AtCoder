#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;
using ll = long long;

template <class T, T (*op)(T, T), T (*e)(), class U>
class RangeTree {
 public:
  using Point = pair<U, U>;
  RangeTree(const RangeTree &) = delete;
  RangeTree &operator=(const RangeTree &) = delete;
  RangeTree(const vector<Point> &points) : points_(points) {
    sort(points_.begin(), points_.end());
    points_.erase(unique(points_.begin(), points_.end()), points_.end());
    size_ = points_.size();
    range_.resize(size_ * 2);
    for (int i = 0; i < size_; ++i) {
      range_[size_ + i] = {Point{points_[i].second, points_[i].first}};
    }
    for (int i = size_ - 1; i >= 0; --i) {
      auto &lch = range_[i * 2];
      auto &rch = range_[i * 2 + 1];
      merge(lch.begin(), lch.end(), rch.begin(), rch.end(),
            back_inserter(range_[i]));
      range_[i].erase(unique(range_[i].begin(), range_[i].end()),
                      range_[i].end());
    }
    for (const auto &v : range_) {
      seg_.emplace_back(v.size());
    }
  }
  RangeTree(const vector<Point> &points, const vector<T> &vals)
      : points_(points) {
    sort(points_.begin(), points_.end());
    points_.erase(unique(points_.begin(), points_.end()), points_.end());
    size_ = points_.size();
    range_.resize(size_ * 2);
    for (int i = 0; i < size_; ++i) {
      range_[size_ + i] = {Point{points_[i].second, points_[i].first}};
    }
    for (int i = size_ - 1; i >= 0; --i) {
      auto &lch = range_[i * 2];
      auto &rch = range_[i * 2 + 1];
      merge(lch.begin(), lch.end(), rch.begin(), rch.end(),
            back_inserter(range_[i]));
      range_[i].erase(unique(range_[i].begin(), range_[i].end()),
                      range_[i].end());
    }
    for (const auto &v : range_) {
      seg_.emplace_back(v.size());
    }
    for (int i = 0; i < (int)points.size(); ++i) {
      Add(points[i], vals[i]);
    }
  }
  void AddPoint(const U &x, const U &y) { points_.emplace_back(x, y); }
  void Set(const U &x, const U &y, const T &val) {
    int i = distance(points_.begin(),
                     lower_bound(points_.begin(), points_.end(), Point{x, y}));
    assert(i < size_ && points_[i] == make_pair(x, y));
    for (i += size_; i > 0; i >>= 1) {
      SetSub(i, {x, y}, val);
    }
  }
  void Set(const Point &p, const T &val) { Set(p.first, p.second, val); }
  void Add(const U &x, const U &y, const T &val) {
    int i = distance(points_.begin(),
                     lower_bound(points_.begin(), points_.end(), Point{x, y}));
    assert(i < size_ && points_[i] == make_pair(x, y));
    for (i += size_; i > 0; i >>= 1) {
      AddSub(i, {x, y}, val);
    }
  }
  void Add(const Point &p, const T &val) { Add(p.first, p.second, val); }
  T Prod(const U &xl, const U &xr, const U &yl, const U &yr) const {
    auto Compare = [](const Point &l, const Point &r) {
      return l.first < r.first;
    };
    int l = size_ + distance(points_.begin(),
                             lower_bound(points_.begin(), points_.end(),
                                         Point{xl, yr}, Compare));
    int r = size_ + distance(points_.begin(),
                             lower_bound(points_.begin(), points_.end(),
                                         Point{xr, yr}, Compare));
    T ret = e();
    while (l < r) {
      if (l & 1) ret = op(ret, ProdSub(l++, yl, yr));
      if (r & 1) ret = op(ret, ProdSub(--r, yl, yr));
      l >>= 1;
      r >>= 1;
    }
    return ret;
  }
  T Get(const U &x, const U &y) const { return Prod(x, x + 1, y, y + 1); }

 private:
  void SetSub(const int &v, const Point &p, const T &val) {
    const int i = distance(range_[v].begin(),
                           lower_bound(range_[v].begin(), range_[v].end(),
                                       Point{p.second, p.first}));
    seg_[v].set(i, val);
  }
  void AddSub(const int &v, const Point &p, const T &val) {
    const int i = distance(range_[v].begin(),
                           lower_bound(range_[v].begin(), range_[v].end(),
                                       Point{p.second, p.first}));
    seg_[v].set(i, op(seg_[v].get(i), val));
  }
  T ProdSub(const int &v, const U &yl, const U &yr) const {
    auto Compare = [&](const Point &l, const Point &r) {
      return l.first < r.first;
    };
    const int i = distance(range_[v].begin(),
                           lower_bound(range_[v].begin(), range_[v].end(),
                                       Point{yl, yl}, Compare));
    const int j = distance(range_[v].begin(),
                           lower_bound(range_[v].begin(), range_[v].end(),
                                       Point{yr, yr}, Compare));
    return seg_[v].prod(i, j);
  }
  int size_;
  vector<Point> points_;
  vector<vector<Point> > range_;
  vector<atcoder::segtree<T, op, e> > seg_;
};

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }
using RT = RangeTree<ll, op, e, ll>;

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll> > points(n);
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    points[i] = {i, a[i]};
  }
  RT rt(points, a);

  int q;
  cin >> q;
  ll z = 0;
  while (q--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll l = a ^ z;
    ll r = b ^ z;
    ll x = c ^ z;
    z = rt.Prod(--l, r, 0, ++x);
    cout << z << endl;
  }

  return 0;
}