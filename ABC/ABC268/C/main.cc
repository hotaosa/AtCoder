#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    int d = p - i;    
    for (int j = -1; j <= 1; ++j) ++cnt[(d + j + n) % n];
  }

  int res = 0;
  for (int i = 0; i < n; ++i) res = max(res, cnt[i]);
  cout << res << endl;  
  return 0;
}
