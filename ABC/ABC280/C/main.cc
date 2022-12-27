#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  s += '0';

  int res = 0;
  while (s[res] == t[res]) ++res;
  cout << ++res << endl;
  
  return 0;
}
