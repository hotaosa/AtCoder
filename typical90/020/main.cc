#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long cc = 1;
  while (b--) cc *= c;
  cout << (a < cc ? "Yes" : "No" ) << endl;
  return 0;
}
