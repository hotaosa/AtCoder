#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, vector<int> > ma;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ma[a].push_back(i);
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;    
    cout << lower_bound(ma[x].begin(), ma[x].end(), r) - lower_bound(ma[x].begin(), ma[x].end(), --l) << endl;
  }
  return 0;
}
