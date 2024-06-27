#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  sort(begin(a), end(a), greater<>());
  sort(begin(b), end(b), greater<>());

  ll res = 0;
  while (!b.empty()) {
    while (!a.empty() && a.back() < b.back()) {
      a.pop_back();
    }
    if (a.empty()) {
      res = -1;
      break;
    }
    res += a.back();
    a.pop_back();
    b.pop_back();
  }

  cout << res << endl;
  return 0;
}