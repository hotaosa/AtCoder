#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  int res = 0;
  for (auto c : s) res += (c == 'v' ? 1 : 2);
  cout << res << endl;  
  return 0;
}
