#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  cout << (s[0] == s[1] && s[1] == s[2] ? "Won" : "Lost") << endl;  
  return 0;
}
