#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool> > mat_l(n, vector<bool>(n, false));
  vector<vector<bool> > mat_r(n, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    mat_l[a][b] = mat_l[b][a] = true;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    mat_r[a][b] = mat_r[b][a] = true;
  }

  auto check = [&](vector<int> o) -> bool {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat_l[i][j] != mat_r[o[i]][o[j]]) return false;
      }
    }
    return true;
  };

  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;
  do {
    if (check(order)) { cout << "Yes" << endl; return 0; }
  } while (next_permutation(order.begin(), order.end()));
  cout << "No" << endl;
  return 0;
}
