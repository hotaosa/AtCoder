#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int main() {
  mint::set_mod(3);
  int n;
  string s;
  cin >> n >> s;

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'b') res += 1LL << i;
    if (s[i] == 'c') res += 1LL << (i + 1);
  }

  cout << res << endl;  
  return 0;
}
