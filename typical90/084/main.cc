#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) v[i] = (s[i] == 'o' ? 1 : 0);
  vector<vector<int> > nx(n + 1, vector<int>(2, n));
  for (int i = n - 1; i >= 0; --i) {
    nx[i][v[i]] = i;
    nx[i][v[i] ^ 1] = nx[i + 1][v[i] ^ 1];
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int r = nx[i + 1][v[i] ^ 1];    
    res += n - r;
  }

  cout << res << endl;  
  return 0;
}
