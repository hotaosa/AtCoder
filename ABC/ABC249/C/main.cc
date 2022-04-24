#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> vs(n);
  for (auto &p : vs) cin >> p;

  int res = 0;
  for (int bit = 0; bit < (1 << n); ++bit) {    
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) for (auto c : vs[i]) ++cnt[c - 'a'];
    }
    int cur = 0;
    for (auto c : cnt) if (c == k) ++cur;
    res = max(res, cur);
  }
  cout << res << endl;  
  return 0;
}
