#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long cur = 0;
  map<long long, long long> ma;
  ++ma[0];
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cur += a * (i & 1 ? 1 : -1);
    ++ma[cur];
  }

  long long res = 0;
  for (auto m : ma) res += m.second * (m.second - 1) / 2;
  cout << res << endl;
  return 0;
}
