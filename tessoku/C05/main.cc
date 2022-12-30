#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  --n;

  string res = "";
  while (n) {
    res += (n & 1 ? '7' : '4');
    n >>= 1;
  }
  while (res.size() < 10) res += '4';
  reverse(res.begin(), res.end());

  cout << res << endl;
  return 0;
}
