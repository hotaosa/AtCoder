#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int Query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int ans;
  cin >> ans;
  assert(ans != -1);
  return ans;
}

void Answer(int ans) {
  assert(ans >= 0 && ans < 100);
  cout << "! " << ans << endl;
}

int main() {
  int n, l, r;
  cin >> n >> l >> r;
  ++r;

  vector<vector<tuple<int, int, int>>> graph((1 << n) + 1);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; (1 << i) * (j + 1) <= (1 << n); ++j) {
      int x = j << i;
      int y = (j + 1) << i;
      graph[x].emplace_back(y, i, j);
      graph[y].emplace_back(x, i, j);
    }
  }

  vector<int> par((1 << n) + 1, -1);
  queue<int> que;
  que.emplace(r);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto [nv, i, j] : graph[v]) {
      if (par[nv] == -1) {
        par[nv] = v;
        que.emplace(nv);
      }
    }
  }

  int res = 0;
  int v = l;
  while (v != r) {
    for (auto [nv, i, j] : graph[v]) {
      if (nv == par[v]) {
        int sign = nv > v ? 1 : -1;
        res = (res + Query(i, j) * sign + 100) % 100;
        v = nv;
        break;
      }
    }
  }

  Answer(res);
  return 0;
}
