#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
  int from, to, w;
  Edge(int from, int to, int w) : from(from), to(to), w(w) { }
};

int main() {
  int l;
  cin >> l;

  int p = 0;
  for (int i = 0; i < 21; ++i) if (l & (1 << i)) p = i;  

  vector<Edge> res;
  for (int i = 0; i < p; ++i) {
    res.emplace_back(i, i + 1, 0);
    res.emplace_back(i, i + 1, 1 << i);
    if (l & (1 << i)) {
      int w = l - (l % (1 << i)) - (1 << i);
      res.emplace_back(i, p, w);
    }
  }
  
  cout << p + 1 << " " << res.size() << endl;
  for (auto r : res) cout << r.from + 1 << " " << r.to + 1 << " " << r.w << endl;  
  return 0;
}
