#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  bool possible = false;
  for (int i = 0; i < n - 2; ++i) possible |= (s[i] == s[i + 1] && s[i] == s[i + 2]);
  cout << (possible ? "Yes" : "No" ) << endl;  
  return 0;
}
