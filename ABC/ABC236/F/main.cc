#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Spice {
  int id;
  long long cost;
  Spice(int id_, long long cost_) : id(id_), cost(cost_) { }
  bool operator<(const Spice &other) const { return cost < other.cost; }
};

int main() {
  int n;
  cin >> n;
  vector<Spice> vs;
  for (int i = 1; i < (1 << n); ++i) {
    int c;
    cin >> c;
    vs.emplace_back(i, c);
  }
  sort(vs.begin(), vs.end());

  long long res = 0;  
  set<int> can_make;
  can_make.insert(0);
  for (int i = 0; i < (1 << n) - 1 && (int)can_make.size() < (1 << n); ++i) {
    int cur = vs[i].id;
    if (can_make.count(cur)) continue;
    res += vs[i].cost;    
    queue<int> que;
    for (auto p : can_make) que.push(p ^ cur);
    while (!que.empty()) { can_make.insert(que.front()); que.pop(); }
  }

  cout << res << endl;
  return 0;
}
