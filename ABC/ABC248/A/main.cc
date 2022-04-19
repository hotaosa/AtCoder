#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  int res = 0;
  for (int i = 1; i <= 9; ++i) {
    res ^= i;
    res ^= s[i - 1] - '0';
  } 
  cout << res << endl;
  return 0;
}
