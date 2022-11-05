#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  char c;
  string s;
  cin >> n >> c >> s;

  map<char, int> mp;
  mp['W'] = 0;
  mp['R'] = 1;
  mp['B'] = 2;

  int sum = 0;
  for (auto ch : s) sum = (sum + mp[ch]) % 3;
  cout << (sum == mp[c] ? "Yes" : "No" ) << endl;    
  return 0;
}
