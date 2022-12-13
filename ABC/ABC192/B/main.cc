#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  bool ok = true;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (i & 1) {
      ok &= s[i] >= 'A' && s[i] <= 'Z';
    } else {
      ok &= s[i] >= 'a' && s[i] <= 'z';
    }
  }

  cout << (ok ? "Yes" : "No" ) << endl;  
  return 0;
}
