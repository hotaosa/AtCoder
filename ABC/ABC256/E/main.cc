#include <iostream>
#include <vector>
#include <atcoder/scc>

using namespace std;
constexpr long long INF = 1LL << 60;

int main() {
  int n;
  cin >> n;  
  vector<long long> c(n);
  atcoder::scc_graph graph(n);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    graph.add_edge(i, --x);
  }
  auto scc_list = graph.scc();

  for (auto &p : c) cin >> p;    
  long long res = 0;

  for (auto vec : scc_list) {
    if (vec.size() > 1) {
      long long add = INF;
      for (auto v : vec) add = min(add, c[v]);
      res += add;
    }
  }
  cout << res << endl;
  return 0;
}