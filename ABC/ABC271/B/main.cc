#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int> > a(n);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    for (int j = 0; j < l; ++j) {
      int aij;
      cin >> aij;
      a[i].push_back(aij);
    }
  }

  while (q--) {
    int s, t;
    cin >> s >> t;
    cout << a[--s][--t] << endl;
  }  
  return 0;
}
