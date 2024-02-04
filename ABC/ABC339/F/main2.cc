// multi_mod

#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;
using ll = long long;

ll TakeMod(const string &s, const ll &mod) {
  ll res = 0;
  for (const auto &c : s) {
    res = res * 10 % mod;
    res = (res + (c - '0')) % mod;
  }
  return res;
}

int main() {
  random_device seed_gen;
  mt19937_64 engine(seed_gen());

  int n;
  cin >> n;
  vector<ll> mods;
  const int siz = 10;
  for (int i = 0; i < siz; ++i) {
    mods.emplace_back(1000000000 + engine() % 1000000000);
  }

  vector a(n, vector<ll>(siz));
  vector<map<ll, int> > mp(siz);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < siz; ++j) {
      a[i][j] = TakeMod(s, mods[j]);
      ++mp[j][a[i][j]];
    }
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int add = n;
      for (int k = 0; k < siz; ++k) {
        ll mul = a[i][k] * a[j][k] % mods[k];
        if (mp[k].count(mul)) {
          add = min(add, mp[k][mul]);
        } else {
          add = 0;
          break;
        }
      }
      res += add;
    }
  }

  cout << res << endl;
  return 0;
}