#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) cin >> vp[i].first >> vp[i].second;
  sort(vp.begin(), vp.end());

  priority_queue<int, vector<int> > pque;
  int res = 0, p = 0;  
  for (int i = 1; i <= d; ++i) {
    while (p < n && vp[p].first <= i) pque.push(vp[p++].second);
    if (!pque.empty()) {
      res += pque.top();
      pque.pop();
    }
  }

  cout << res << endl;  
  return 0;
}
