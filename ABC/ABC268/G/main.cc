#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;
  vector<pair<string, int> > vsp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vsp[i].first;
    vsp[i].second = i;
  }

  vector<mint> res(n, 0);
  sort(vsp.begin(), vsp.end());
  for (int i = 0; i < n; ++i) res[vsp[i].second] += i + 1;

  for (int i = 0; i < n; ++i) {
    for (auto &c : vsp[i].first) c = 'z' - (c - 'a');
  }

  sort(vsp.begin(), vsp.end());
  for (int i = 0; i < n; ++i) res[vsp[i].second] += i + 1;

  for (int i = 0; i < n; ++i) cout << (res[i] / 2).val() << endl;  
  return 0;
}
