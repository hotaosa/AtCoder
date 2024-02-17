#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  for (int i = 0; i < n - 1; ++i) {
    ll s, t;
    cin >> s >> t;
    a[i + 1] += a[i] / s * t;
  }

  cout << a.back() << endl;
  return 0;
}