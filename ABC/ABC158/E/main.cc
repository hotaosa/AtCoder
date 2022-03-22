#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, p;
  string s;
  cin >> n >> p >> s;

  if (p == 2 || p == 5) {
    long long res = 0;
    for (int i = 0; i < n; ++i) if ((s[i] - '0') % p == 0) res += i + 1;
    cout << res << endl;
    return 0;
  }

  vector<long long> pow10_mod(n + 1);
  pow10_mod[0] = 1;
  for (int i = 0; i < n; ++i) pow10_mod[i + 1] = pow10_mod[i] * 10 % p;    

  vector<long long> cnt(p, 0);
  ++cnt[0];
  long long res = 0;

  int cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur = (cur + (s[i] - '0') * pow10_mod[n - 1 - i]) % p;
    res += cnt[cur];
    ++cnt[cur];    
  }

  cout << res << endl;  
  return 0;
}
