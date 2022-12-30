#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  atcoder::mf_graph<int> graph(n + 26);
  for (int i = 0; i < n; ++i) {
    graph.add_edge(n, i, 10);
    string s;
    cin >> s;
    for (int j = 0; j < 24; ++j) {
      if (s[j] == '1') {
        graph.add_edge(i, n + 2 + j, 1);
      }
    }
  }
  for (int i = 0; i < 24; ++i) {
    graph.add_edge(n + 2 + i, n + 1, m);
  }

  cout << (graph.flow(n, n + 1) == m * 24 ? "Yes" : "No") << endl;
  return 0;
}
