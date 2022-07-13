#include <iostream>
#include <vector>
#include <map>

using namespace std;

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

void dfs(const vector<vector<int> > &graph, vector<bool> &used, int v, long long &cnt_x, long long &cnt_y, const int siz_x) {
  used[v] = true;
  if (v < siz_x) ++cnt_x;
  else ++cnt_y;
  for (int nv : graph[v]) {
    if (!used[nv]) dfs(graph, used, nv, cnt_x, cnt_y, siz_x);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  int siz_x = vcomp(x);
  int siz = vcomp(y);
  for (auto &p : y) p += siz_x;
  siz += siz_x;

  vector<vector<int> > graph(siz);
  for (int i = 0; i < n; ++i) {
    graph[x[i]].push_back(y[i]);
    graph[y[i]].push_back(x[i]);
  }

  long long res = -n;
  vector<bool> used(siz, false);
  for (int i = 0; i < siz; ++i) {
    if (used[i]) continue;
    long long cnt_x = 0, cnt_y = 0;
    dfs(graph, used, i, cnt_x, cnt_y, siz_x);
    res += cnt_x * cnt_y;
  }
  cout << res << endl;
}