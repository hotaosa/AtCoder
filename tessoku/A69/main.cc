#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  atcoder::mf_graph<int> graph(n * 2 + 2);
  for (int i = 0; i < n; ++i) {
    graph.add_edge(n * 2, i, 1);
    graph.add_edge(n + i, n * 2 + 1, 1);
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) if (s[j] == '#') graph.add_edge(i, n + j, 1);
  }

  cout << graph.flow(n * 2, n * 2 + 1) << endl;  
  return 0;
}
