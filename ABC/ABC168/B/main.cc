#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;

  if ((int)s.size() <= k) cout << s << endl;
  else cout << s.substr(0, k) << "..." << endl;
  return 0;
}
