#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  map<char, int> mp;
  mp['a'] = 0;
  mp['t'] = 1;
  mp['c'] = 2;
  mp['o'] = 3;
  mp['d'] = 4;
  mp['e'] = 5;
  mp['r'] = 6;

  string s;
  cin >> s;  
  int res = 0;
  for (int i = 0; i < 6; ++i) {
    for (int j = i + 1; j < 7; ++j) {
      if (mp[s[i]] > mp[s[j]]) ++res;
    }
  }
  cout << res << endl;  
  return 0;
}
