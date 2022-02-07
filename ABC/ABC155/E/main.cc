#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();

  vector<int> v(n + 1, 0);  
  for (int i = 0; i < n; ++i) v[i] = s[n - 1 - i] - '0';
  
  int res = 0;
  for (int i = 0; i <= n; ++i) {
    if (v[i] > 5 || (v[i] == 5 && v[i + 1] >= 5)) {
      ++v[i + 1];      
      v[i] = 10 - v[i];
    } 
    res += v[i];
  }
  cout << res << endl;
  return 0;
}
