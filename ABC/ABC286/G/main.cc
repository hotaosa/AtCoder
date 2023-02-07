#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> u(m), v(m);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    --u[i];
    --v[i];
  }

  vector<bool> inc(m, false);
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    inc[--x] = true;
  }

  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    if (!inc[i]) {
      uf.merge(u[i], v[i]);
    }
  }

  vector<int> deg(n, 0);
  for (int i = 0; i < m; ++i) {
    if (inc[i]) {
      deg[uf.leader(u[i])] ^= 1;
      deg[uf.leader(v[i])] ^= 1;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += deg[i];
  }

  cout << (cnt == 0 || cnt == 2 ? "Yes" : "No") << endl;
  return 0;
}
