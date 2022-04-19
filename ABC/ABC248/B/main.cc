#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long a, b, k;
  cin >> a >> b >> k;
  int res = 0;
  while (a < b && ++res) a *= k;
  cout << res << endl;
  return 0;
}
