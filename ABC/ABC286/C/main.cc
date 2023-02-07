#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long Count(string s) {
  int l = 0, r = s.size() - 1;
  long long ret = 0;
  while (l < r) {
    if (s[l++] != s[r--]) ++ret;
  }
  return ret;
}

int main() {
  int n;
  long long a, b;
  string s;
  cin >> n >> a >> b >> s;
  s += s;

  long long res = 1LL << 60;
  for (int i = 0; i < n; ++i) {
    res = min(res, a * i + b * Count(s.substr(i, n)));
  }

  cout << res << endl;  
  return 0;
}
