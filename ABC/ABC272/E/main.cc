#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<int> > memo(m + 1);
  for (int i = 0; i < n; ++i) {
    int cur = a[i], cnt = 1;
    if (cur < 0) {
      cnt = (i - cur) / (i + 1);      
    }
    cur += cnt * (i + 1);
    while (cnt <= m && cur < n) {
      memo[cnt].push_back(cur);
      cur += (i + 1);
      ++cnt;
    }
  }
  
  for (int i = 1; i <= m; ++i) {
    memo[i].push_back(n + 1);
    sort(memo[i].begin(), memo[i].end());
    memo[i].erase(unique(memo[i].begin(), memo[i].end()), memo[i].end());
    int res = 0;
    while (memo[i][res] == res) ++res;
    cout << res << endl;
  }  
  return 0;
}
