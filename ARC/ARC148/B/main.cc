#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

string func(string s, int i, int j) {
  reverse(s.begin() + i, s.begin() + j);
  for (int k = i; k < j; ++k) s[k] = (s[k] == 'd' ? 'p' : 'd');
  return s;
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  int p = 0;
  while (p < n && s[p] == 'd') ++p;  

  string res = s;
  for (int i = p + 1; i <= n; ++i) {
    string cur = func(s, p, i);
    res = min(res, cur);
  }
    
  cout << res << endl;  
  return 0;
}
