#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
  int to, val;
  Edge(int to, int val) : to(to), val(val) { }
};

int main() {
  int q;
  cin >> q;

  vector<vector<Edge> > graph(q + 1);
  map<int, int> mp;

  for (int i = 1; i <= q; ++i) {
    string query;
    cin >> query;
    if (query == "ADD") {
      int val;
      cin >> val;
      graph[i - 1].emplace_back(i, val);
    } else if (query == "DELETE") {
      graph[i - 1].emplace_back(i, -1);
    } else if (query == "SAVE") {
      int page;
      cin >> page;
      mp[page] = i;
      graph[i - 1].emplace_back(i, 0);
    } else {
      int page;
      cin >> page;
      graph[mp[page]].emplace_back(i, 0);
    }
  }

  stack<int> st;
  vector<int> res(q + 1, -1);
  auto dfs = [&](auto dfs, int v) -> void {
    if (!st.empty()) res[v] = st.top();
    for (auto e : graph[v]) {
      if (e.val == -1) {
        int tmp = -1;
        if (!st.empty()) {
          tmp = st.top();
          st.pop();
        }
        dfs(dfs, e.to);
        if (tmp != -1) st.push(tmp);
      } else if (e.val == 0) {
        dfs(dfs, e.to);
      } else {
        st.push(e.val);
        dfs(dfs, e.to);
        st.pop();
      }
    }
  };

  dfs(dfs, 0);
  for (int i = 1; i <= q; ++i) cout << res[i] << " ";
  cout << endl;  
  return 0;
}
