#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int SIZE = 400000;

int main() {
  int n;
  cin >> n;

  vector<int> edge(SIZE, 0);
  atcoder::dsu uf(SIZE);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (uf.same(a, b)) {
      ++edge[uf.leader(a)];
      continue;
    }        
    a = uf.leader(a);
    b = uf.leader(b);    
    uf.merge(a, b);
    if (uf.leader(a) == a) edge[a] += edge[b] + 1;
    else edge[b] += edge[a] + 1;
  }

  int res = 0;
  for (int i = 0; i < SIZE; ++i) {
    if (uf.leader(i) == i) {
      if (edge[i] == uf.size(i) - 1) res += uf.size(i) - 1;
      else res += uf.size(i);
    }
  }
  cout << res << endl;  
  return 0;
}
