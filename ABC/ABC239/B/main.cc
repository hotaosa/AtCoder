#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long x;
  cin >> x;
  if (x >= 0) cout << x / 10 << endl;
  else cout << (x - 9) / 10 << endl;
  return 0;
}
