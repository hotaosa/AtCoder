#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> x(n), y(n), p(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> p[i];

  auto possible = [&](int i, int j, long long s) -> bool {
    return p[i] * s >= abs(x[i] - x[j]) + abs(y[i] - y[j]);
  };

  auto judge = [&](long long s) -> bool {
    vector<vector<int> > graph(n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (j != i && possible(i, j, s)) graph[i].push_back(j);
    
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      vector<bool> visited(n, false);
      visited[i] = true;
      queue<int> que;
      que.push(i);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (++cnt == n) return true;
        for (auto nv : graph[v]) {
          if (!visited[nv]) {
            visited[nv] = true;
            que.push(nv);
          }
        }
      }
    }
    return false;
  };

  long long l = 0, r = 4000000000;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    (judge(m) ? r : l) = m;
  }

  cout << r << endl;
  return 0;
}