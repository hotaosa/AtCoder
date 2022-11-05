#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    vp.emplace_back(r, l);
  }
  sort(vp.begin(), vp.end());

  int res = 0, cur = -1;
  for (int i = 0; i < n; ++i) {
    auto [r, l] = vp[i];
    if (l >= cur) {
      ++res;
      cur = r;
    }
  }

  cout << res << endl;  
  return 0;
}
