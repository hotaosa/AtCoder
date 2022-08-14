#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int l, r;
  cin >> l >> r;
  string res = "atcoder";
  res = res.substr(l - 1, r - l + 1);
  cout << res << endl;
  return 0;
}
