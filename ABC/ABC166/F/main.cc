#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  vector<int> val(3, 0);
  cin >> n;
  for (auto &p : val) cin >> p;
  vector<pair<int, int> > query(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int p1 = s[0] - 'A', p2 = s[1] - 'A';
    query[i] = {p1, p2};
  }

  vector<vector<int> > nx(3, vector<int>(n + 1, -1));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 3; ++j) nx[j][i] = nx[j][i + 1];
    int p1 = query[i].first, p2 = query[i].second;
    nx[p1][i] = i;
    nx[p2][i] = i;
  }

  vector<char> res(n);
  for (int i = 0; i < n; ++i) {
    int p1 = query[i].first, p2 = query[i].second;
    if (val[p1] == 0 && val[p2] == 0) { cout << "No" << endl; return 0; }
    if (val[p1] == 1 && val[p2] == 1 && i < n - 1) {
      int nx1 = query[i + 1].first, nx2 = query[i + 1].second;
      if (nx1 != p1 && nx1 != p2 && val[nx1] == 0 && p1 != nx2) swap(p1, p2);
      if (nx2 != p1 && nx2 != p2 && val[nx2] == 0 && p1 != nx1) swap(p1, p2);
    }
    if (val[p1] > val[p2]) swap(p1, p2);
    ++val[p1];
    --val[p2];
    res[i] = 'A' + p1;
  }
  cout << "Yes" << endl;
  for (char c : res) cout << c << endl;
  return 0;
}
