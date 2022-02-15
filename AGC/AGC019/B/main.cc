#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();

  vector<long long> cnt(26, 0);
  for (auto c : s) ++cnt[c - 'a'];
  
  long long res = 0;
  for (int i = 0; i < 26; ++i) res += cnt[i] * (n - cnt[i]);
  cout << res / 2 + 1 << endl;
  return 0;
}
