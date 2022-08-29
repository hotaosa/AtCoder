#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  s += s[0];
  cout << s.substr(1, s.size() - 1) << endl;  
  return 0;
}
