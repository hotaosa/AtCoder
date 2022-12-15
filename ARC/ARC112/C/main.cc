#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Child {
  int diff;
  bool rev;
  Child(int d, bool r) : diff(d), rev(r) { }
  bool operator<(const Child &other) const {
    if (rev == other.rev) {
      return diff > other.diff;
    }
    if (rev) {
      return other.diff < 0;
    } else {
      return diff >= 0;
    }
  }
};

int main() {
  int n;
  cin >> n;

  vector<vector<int> > graph(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    graph[--p].push_back(i);
  }

  auto dfs = [&](auto dfs, int v) -> Child {
    vector<Child> ch;
    for (auto nv : graph[v]) ch.emplace_back(dfs(dfs, nv));
    sort(ch.begin(), ch.end());

    int d = -1, r = 1;
    for (auto c : ch) {
      d += r ? c.diff : -(c.diff);
      r ^= c.rev;
    }
    assert(abs(d) <= n);
    assert(r == 0 || r == 1);

    return Child(d, r);
  };

  cout << (n - dfs(dfs, 0).diff) / 2 << endl;
  return 0;
}
