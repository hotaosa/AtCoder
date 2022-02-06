#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int> > t(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> t[i][j];

  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;

  int res = 0;
  do {
    int cur = 0;
    for (int i = 1; i < n; ++i) cur += t[order[i]][order[i - 1]];
    cur += t[order[0]][order.back()];
    if (cur == k) ++res;
  } while (next_permutation(order.begin() + 1, order.end()));

  cout << res << endl;
  return 0;
}
