#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  set<int> se;
  vector<int> res(n, -1);
  for (int i = 0; i < n; ++i) {
    if (i + k >= n && i - k >= 0) res[i - k] = i;
    else se.insert(i);
  }

  for (int i = 0; i < n; ++i) {
    if (res[i] != -1) continue;
    if (abs(i - *se.begin()) >= k) {
      res[i] = *se.begin();
      se.erase(se.begin());
    } else {
      auto p = se.lower_bound(i + k);
      if (p == se.end()) {
        cout << "-1" << endl;
        return 0;
      }
      res[i] = *p;
      se.erase(p);
    }
  }
  for (auto r : res) cout << r + 1 << " ";
  cout << endl;
  return 0;
}
