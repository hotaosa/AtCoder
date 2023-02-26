#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<string> vs(k);
  for (auto &p : vs) cin >> p;
  sort(vs.begin(), vs.end());
  for (auto s : vs) cout << s << endl;
  return 0;
}
