#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<long long, int> > x(n), y(n);
  for (int i = 0; i < n; ++i) {
    long long xi, yi;
    cin >> xi >> yi;
    x[i] = {xi, i};
    y[i] = {yi, i};
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  vector<tuple<long long, int, int> > edges;
  for (int i = 0; i < n - 1; ++i) {
    edges.emplace_back(x[i + 1].first - x[i].first, x[i].second, x[i + 1].second);
    edges.emplace_back(y[i + 1].first - y[i].first, y[i].second, y[i + 1].second);
  }
  sort(edges.begin(), edges.end());

  atcoder::dsu uf(n);
  long long res = 0;
  for (auto e : edges) {
    long long cost = get<0>(e);
    int u = get<1>(e);
    int v = get<2>(e);
    if (!uf.same(u, v)) {
      uf.merge(u, v);
      res += cost;
    }
  }
  cout << res << endl;  
  return 0;
}
