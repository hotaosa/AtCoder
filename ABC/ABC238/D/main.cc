#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, s;
    cin >> a >> s;
    cout << (s >= 2 * a && !((s - 2 * a) & a) ? "Yes" : "No" ) << endl;
  }
  return 0;
}
