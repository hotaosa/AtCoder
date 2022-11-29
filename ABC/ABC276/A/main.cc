#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  int res = -1;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'a') res = i + 1;
  }

  cout << res << endl;  
  return 0;
}
