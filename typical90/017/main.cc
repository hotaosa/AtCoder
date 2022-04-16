#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int> > vp(m);
  for (int i = 0; i < m; ++i) {
    cin >> vp[i].first >> vp[i].second;
    --vp[i].first;
    --vp[i].second;
  }

  sort(vp.begin(), vp.end());
  queue<int> que;
  atcoder::fenwick_tree<int> bit(n + 1);
  long long res = 0;

  for (int i = 0; i < m; ++i) {
    if (i > 0 && vp[i].first > vp[i - 1].first) {
      while (!que.empty()) { bit.add(que.front(), 1); que.pop(); }
    }
    res += bit.sum(vp[i].first + 1, vp[i].second);
    que.push(vp[i].second);
  }

  cout << res << endl;
  return 0;
}
