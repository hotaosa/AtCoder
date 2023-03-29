#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  string s;
  cin >> s;

  vector<long long> cnt(1 << 10, 0);
  cnt[0] = 1;

  int cur = 0;
  long long res = 0;
  for (const auto &c : s) {
    cur ^= (1 << (c - '0'));
    res += cnt[cur]++;
  }

  cout << res << endl;  
  return 0;
}
