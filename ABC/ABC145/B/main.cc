#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  if (n & 1) { cout << "No" << endl; return 0; }

  string t = s.substr(n / 2, n / 2);
  s = s.substr(0, n / 2);
  cout << (s == t ? "Yes" : "No" ) << endl;  
  return 0;
}
