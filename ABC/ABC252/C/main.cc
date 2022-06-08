#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > place(n, vector<int>(10));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < 10; ++j) place[i][s[j] - '0'] = j;
  }

  int res = 1 << 30;
  for (int i = 0; i < 10; ++i) {
    set<int> se;
    for (int j = 0; j < n; ++j) {
      while (!se.insert(place[j][i]).second) place[j][i] += 10;
    }
    res = min(res, *se.rbegin());
  }
  cout << res << endl;
  return 0;
}
