#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

struct House {
  int id, money;
  vector<int> key;
  House(int id_, int money_) : id(id_), money(money_) { }
  bool operator<(const House &other) const { return money < other.money; }
};

int main() {
  int n, w;
  cin >> n >> w;

  atcoder::mf_graph<int> graph(n + 2);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    res += a;
    graph.add_edge(0, i, a);
    graph.add_edge(i, n + 1, w);
  }
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int c;
      cin >> c;
      graph.add_edge(c, i, INF);
    }
  }
  res -= graph.flow(0, n + 1);
  cout << res << endl;
  return 0;
}
