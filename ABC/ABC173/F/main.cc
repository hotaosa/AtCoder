#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<pair<int, int> > edges;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    edges.emplace_back(--u, --v);
  }

  long long res = (n * n * n + 3 * n * n + 2 * n) / 6;
  for (auto [u, v] : edges) {
    res -= (long long)(u + 1) * (n - v);
  }

  cout << res << endl;  
  return 0;
}
