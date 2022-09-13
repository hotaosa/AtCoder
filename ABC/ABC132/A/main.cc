#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  map<char, int> mp;
  for (auto c : s) ++mp[c];

  cout << (mp.size() == 2 && mp[s[0]] == 2? "Yes" : "No" ) << endl;  
  return 0;
}
