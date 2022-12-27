#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Point2d {
  Point2d(const int &x, const int &y) : x(x), y(y) { }
  int x, y;
};

struct Edge {
  Edge(const int &u, const int &v, const long long &w) : u(u), v(v), w(w) { }
  int u, v;
  long long w;
  bool operator<(const Edge &other) const {
    if (w != other.w) return w < other.w;
    if (u != other.u) return u < other.u;
    return v < other.v;
  }
};

class ManhattanMST {
 public:
  ManhattanMST(const vector<Point2d> &points) : size_(points.size()), points_(points) {
    Build();
  }
  vector<Edge> MSTEdges() const {
    vector<Edge> ret;
    atcoder::dsu uf(size_);
    for (auto e: edges_) {
      if (!uf.same(e.u, e.v)) {
        uf.merge(e.u, e.v);
        ret.emplace_back(e.u, e.v, Dist(e.u, e.v));
      }
    }
    return ret;
  }

 private:
  int size_;
  vector<Point2d> points_;
  vector<Edge> edges_;

  long long Dist(const int &u, const int &v) const {
    return abs(points_[u].x - points_[v].x) + abs(points_[u].y - points_[v].y);
  }
  void Build() {
    vector<int> order(size_);
    iota(order.begin(), order.end(), 0);
    for (int s = 0; s < 2; ++s) {
      for (int t = 0; t < 2; ++t) {
        sort(order.begin(), order.end(), [&](int i, int j) {
          return points_[i].x + points_[i].y < points_[j].x + points_[j].y;
        });
        map<int, int, greater<>> mp;
        for (auto i : order) {
          for (auto iter = mp.lower_bound(points_[i].y); iter != mp.end(); iter = mp.erase(iter)) {
            int j = iter->second;
            int dx = points_[i].x - points_[j].x;
            int dy = points_[i].y - points_[j].y;
            if (dy > dx) break;
            edges_.emplace_back(i, j, Dist(i, j));
          }
          mp[points_[i].y] = i;
        }
        for (auto &point : points_) swap(point.x, point.y);
      }
      for (auto &point : points_) point.x *= -1;
    }
    sort(edges_.begin(), edges_.end());
  }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<Point2d> vp;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    vp.emplace_back(i, --p);
  }

  ManhattanMST mst(vp);
  auto edges = mst.MSTEdges();

  vector<long long> res(n, INF);
  for (auto e : edges) {
    chmin(res[e.u], e.w);
    chmin(res[e.v], e.w);
  }

  for (auto r : res) cout << r << " ";
  cout << endl;

  return 0;
}
