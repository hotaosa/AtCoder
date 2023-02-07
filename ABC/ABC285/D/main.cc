#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  atcoder::scc_graph graph(2 * n);
  map<string, int> mp;
  for (int i = 0; i < n; ++i) {
    string s, t;
    cin >> s >> t;
    int si = mp.count(s) ? mp[s] : mp.size();
    mp[s] = si;
    int ti = mp.count(t) ? mp[t] : mp.size();
    mp[t] = ti;
    graph.add_edge(si, ti);
  }

  auto v = graph.scc();
  cout << ((int)v.size() == 2 * n ? "Yes" : "No" ) << endl;
  return 0;
}
