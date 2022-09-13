#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  auto node_source = [&](int i) -> int { return i; };
  auto node_sink = [&](int i) -> int { return n + i; };
  auto row = [&](int i) -> int { return n * 2 + i; };
  auto column = [&](int i) -> int { return n * 2 + h + i; };

  int s = n * 2 + h + w;
  int t = s + 1;

  atcoder::mf_graph<int> graph(n * 2 + h + w + 2);
  for (int i = 0; i < n; ++i) graph.add_edge(node_source(i), node_sink(i), 1);
  for (int i = 0; i < h; ++i) graph.add_edge(s, row(i), 1);
  for (int i = 0; i < w; ++i) graph.add_edge(column(i), t, 1);

  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = --a; j < c; ++j) graph.add_edge(row(j), node_source(i), 1);
    for (int j = --b; j < d; ++j) graph.add_edge(node_sink(i), column(j), 1);
  }

  cout << graph.flow(s, t) << endl;
  return 0;
}
