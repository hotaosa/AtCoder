#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n - 1));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n - 1; ++j) { cin >> a[i][j]; --a[i][j]; }
  vector<int> nx(n, 0);

  int res = -1;
  while (true) {
    bool updated = false;
    ++res;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      if (nx[i] == n - 1) continue;
      int j = a[i][nx[i]];
      if (nx[j] < n - 1 && a[j][nx[j]] == i && !used[j]) {
        used[i] = used[j] = true;
        updated = true;
        ++nx[i];
        ++nx[j];
      }
    }
    if (!updated) break;
  }

  for (int i = 0; i < n; ++i) if (nx[i] < n - 1) { cout << "-1" << endl; return 0; }
  cout << res << endl;
  return 0;
}
