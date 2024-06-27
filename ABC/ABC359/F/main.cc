#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

inline ll Square(ll x) { return x * x; }

inline ll Cost(pair<ll, ll> x) { return Square(x.second) * x.first; }

struct Compare {
  bool operator()(pair<ll, ll> x, pair<ll, ll> y) {
    auto dx = (2 * x.second + 1) * x.first;
    auto dy = (2 * y.second + 1) * y.first;
    return dx > dy;
  }
};

int main() {
  int n;
  cin >> n;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> pque;

  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    pque.emplace(a, 1);
  }

  for (int i = 0; i < n - 2; ++i) {
    auto [a, deg] = pque.top();
    pque.pop();
    pque.emplace(a, ++deg);
  }

  ll res = 0;
  while (!pque.empty()) {
    auto p = pque.top();
    pque.pop();
    res += Cost(p);
  }

  cout << res << endl;
  return 0;
}