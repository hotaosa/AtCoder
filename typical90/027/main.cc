#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> se;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if (se.insert(s).second) cout << i << endl;
  }
  return 0;
}
