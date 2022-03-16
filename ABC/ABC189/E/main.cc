#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

using vec = vector<long long>;
using mat = vector<vec>;

mat mat_mul(const mat &a, const mat &b) {  
  mat ret(a.size(), vec(b[0].size()));
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int k = 0; k < (int)b.size(); ++k) {
      for (int j = 0; j < (int)b[0].size(); ++j) {
        ret[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ret;
}

int main() {  
  int n;
  cin >> n;
  vector<mat> point(n, mat(3, vec(1, 1)));
  for (int i = 0; i < n; ++i) cin >> point[i][0][0] >> point[i][1][0];
  int m;
  cin >> m;
  vector<mat> vm(m + 1);
  vm[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  for (int i = 0; i < m; ++i) {
    int op;
    cin >> op;
    if (op == 1) vm[i + 1] = mat_mul({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}, vm[i]);
    else if (op == 2) vm[i + 1] = mat_mul({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}, vm[i]);
    else {
      int p;
      cin >> p;
      if (op == 3) vm[i + 1] = mat_mul({{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}}, vm[i]);
      else vm[i + 1] = mat_mul({{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}}, vm[i]);
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int a, b;
    cin >> a >> b;
    mat res = mat_mul(vm[a], point[--b]);
    cout << res[0][0] << " " << res[1][0] << endl;
  }  
  return 0;
}
