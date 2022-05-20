#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if (k > (n - 1) * (n - 2) / 2) { cout << "-1" << endl; return 0; }
  
  vector<vector<int> > edge(n, vector<int>(n, 0));
  for (int i = 1; i < n; ++i) edge[0][i] = edge[i][0] = 1;

  int m = n - 1;
  int cur = (n - 1) * (n - 2) / 2;
  int i = 1, j = 2;
  while (cur > k) {
    if (edge[i][j] == 0) {
      edge[i][j] = edge[j][i] = 1;
      ++m;
      --cur;
    }
    if (j < n - 1) ++j;
    else j = ++i + 1;          
  }

  cout << m << endl;
  for (int i = 0; i < n - 1; ++i) for (int j = i + 1; j < n; ++j) if (edge[i][j] == 1) cout << i + 1 << " " << j + 1 << endl;
  return 0;
}
