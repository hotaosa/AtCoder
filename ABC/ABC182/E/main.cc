#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, n, m;
  cin >> h >> w >> n >> m;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }

  vector<vector<int> > block_r(h, {-1, w}), block_c(w, {-1, h});
  for (int i = 0; i < m; ++i) {
    int c, d;
    cin >> c >> d;
    --c; --d;
    block_r[c].push_back(d);
    block_c[d].push_back(c);
  }
  for (auto &v : block_r) sort(v.begin(), v.end());
  for (auto &v : block_c) sort(v.begin(), v.end());  

  vector<vector<int> > cnt_r(h + 1, vector<int>(w + 1, 0));
  vector<vector<int> > cnt_c(h + 1, vector<int>(w + 1, 0));
  for (int i = 0; i < n; ++i) {
    ++cnt_r[a[i]][*(--lower_bound(block_r[a[i]].begin(), block_r[a[i]].end(), b[i])) + 1];
    --cnt_r[a[i]][*lower_bound(block_r[a[i]].begin(), block_r[a[i]].end(), b[i])];
    ++cnt_c[*(--lower_bound(block_c[b[i]].begin(), block_c[b[i]].end(), a[i])) + 1][b[i]];
    --cnt_c[*lower_bound(block_c[b[i]].begin(), block_c[b[i]].end(), a[i])][b[i]];
  }
  
  for (int i = 0; i <= h; ++i) for (int j = 1; j <= w; ++j) cnt_r[i][j] += cnt_r[i][j - 1];
  for (int i = 1; i <= h; ++i) for (int j = 0; j <= w; ++j) cnt_c[i][j] += cnt_c[i - 1][j];  

  int res = 0;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (cnt_r[i][j] | cnt_c[i][j]) ++res;
  cout << res << endl;  
  return 0;
}
