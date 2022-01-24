#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> local(n);
  for (auto &p : local) cin >> p;
  map<string, bool> express;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    express[s] = true;
  }
  for (auto &p : local) cout << (express[p] ? "Yes" : "No" ) << endl;
  return 0;
}
