#include <iostream>
#include <vector>
//
#include <atcoder/dsu>

using namespace std;

struct Edge {
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator<(const Edge &other) const { return w < other.w; }
  bool operator<=(int x) const { return w <= x; }
};

int main() {
  int h, w, y;
  cin >> h >> w >> y;
  h += 2;
  w += 2;

  vector a(h, vector<int>(w, 0));
  for (int i = 1; i < h - 1; ++i) {
    for (int j = 1; j < w - 1; ++j) {
      cin >> a[i][j];
    }
  }

  vector<Edge> edges;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i < h - 1) {
        edges.emplace_back(i * w + j, (i + 1) * w + j,
                           max(a[i][j], a[i + 1][j]));
      }
      if (j < w - 1) {
        edges.emplace_back(i * w + j, i * w + j + 1, max(a[i][j], a[i][j + 1]));
      }
    }
  }
  sort(rbegin(edges), rend(edges));

  atcoder::dsu uf(h * w);
  for (int i = 1; i <= y; ++i) {
    while (!edges.empty() && edges.back() <= i) {
      auto e = edges.back();
      edges.pop_back();
      uf.merge(e.u, e.v);
    }
    cout << h * w - uf.size(0) << endl;
  }

  return 0;
}