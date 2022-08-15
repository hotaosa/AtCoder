#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void solve(int n, int m, vector<int> &cur) {
  if ((int)cur.size() == n) {
    for (int r : cur) cout << r << " ";
    cout << endl;
    return;
  }
  for (int nx = (cur.empty() ? 1 : cur.back() + 1); nx <= m; ++nx) {
    cur.push_back(nx);
    solve(n, m, cur);
    cur.pop_back();
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cur;
  solve(n, m, cur);  
  return 0;
}
