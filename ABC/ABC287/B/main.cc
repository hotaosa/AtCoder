#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> vs(n);
  for (auto &p : vs) cin >> p;

  set<string> se;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    se.insert(s);
  }

  int cnt = 0;
  for (auto s : vs) {
    cnt += se.count(s.substr(3, 3));
  }

  cout << cnt << endl;  
  return 0;
}
