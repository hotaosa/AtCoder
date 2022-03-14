#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  int q;
  cin >> s >> q;

  auto g = [&](char c, long long a) -> char {
    return (char)('A' + (c - 'A' + a) % 3);
  };

  auto f = [&](auto f, long long t, long long k) -> char {
    if (t == 0) return s[k];
    else if (k == 0) return g(s[0], t);
    else return g(f(f, t - 1, k / 2), k % 2 + 1);
  };

  while (q--) {
    long long t, k;
    cin >> t >> k;
    cout << f(f, t, k - 1) << endl;
  }
  return 0;
}
