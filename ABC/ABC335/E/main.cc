#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

template<class T> inline bool ChangeMax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto &e : a) cin >> e;

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if (a[--u] <= a[--v]) {
      graph[u].emplace_back(v);
    }
    if (a[u] >= a[v]) {
      graph[v].emplace_back(u);
    }
  }

  vector<int> score(n, 0);
  score[0] = 1;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > pque;
  pque.emplace(a[0], -1, 0);

  while (!pque.empty()) {
    int s, v;
    tie(ignore, s, v) = pque.top();
    pque.pop();
    if (s > -score[v]) continue;
    for (int nv : graph[v]) {
      if (a[nv] == a[v]) {
        if (ChangeMax(score[nv], score[v])) {
          pque.emplace(a[nv], -score[nv], nv);
        }
      } else {
        if (ChangeMax(score[nv], score[v] + 1)) {
          pque.emplace(a[nv], -score[nv], nv);
        }
      }
    }
  }

  cout << score.back() << endl;
  return 0;
}