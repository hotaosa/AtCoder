#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<pair<int, int> > > ch(c);
  for (int i = 0; i < n; ++i) {
    int s, t, cc;
    cin >> s >> t >> cc;
    ch[--cc].push_back(make_pair(s * 2 - 1, t * 2));
  }
  for (int i = 0; i < c; ++i) {
    sort(ch[i].begin(), ch[i].end());
    if (!ch[i].empty()) --ch[i][0].first;
    for (int j = 1; j < (int)ch[i].size(); ++j) if (ch[i][j - 1].second - ch[i][j].first == 1) ++ch[i][j].first;
  }

  vector<int> sum(200001, 0);
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < (int)ch[i].size(); ++j) {
      ++sum[ch[i][j].first];
      --sum[ch[i][j].second];
    }
  }
  int res = 0;
  for (int i = 1; i < (int)sum.size(); ++i) {
    sum[i] += sum[i - 1];
    res = max(res, sum[i]);
  }
  cout << res << endl;
  return 0;
}
