#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int res = 1;
  while (b--) res *= a;
  cout << res << endl;

  return 0;
}
