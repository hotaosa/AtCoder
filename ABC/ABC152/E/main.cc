#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

map<int, int> prime_factorization(int a) {
  map<int, int> pf;
  for (int i = 2; i * i <= a; ++i) {
    while (a % i == 0) {
      ++pf[i];
      a /= i;
    }    
  }
  if (a) ++pf[a];
  return pf;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  map<int, int> ma;
  for (int i = 0; i < n; ++i) {
    map<int, int> pf = prime_factorization(a[i]);
    for (auto m : pf) chmax(ma[m.first], m.second);
  }

  mint l = 1;
  for (auto m : ma) for (int i = 0; i < m.second; ++i) l *= m.first;
  mint res = 0;
  for (int i = 0; i < n; ++i) res += l / a[i];
  cout << res.val() << endl;
  return 0;
}
