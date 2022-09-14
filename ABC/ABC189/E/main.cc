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
  vector<mat> points(n, mat(3, vec(1, 1)));
  for (int i = 0; i < n; ++i) cin >> points[i][0][0] >> points[i][1][0];

  int m;
  cin >> m;
  vector<mat> op(m + 1, mat(3, vec(3, 0)));
  for (int i = 0; i < 3; ++i) op[0][i][i] = 1;
  
  for (int i = 1; i <= m; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      op[i] = {{0, 1, 0},
               {-1, 0, 0},
               {0, 0, 1}};
    } else if (t == 2) {
      op[i] = {{0, -1, 0},
               {1, 0, 0},
               {0, 0, 1}};
    } else if (t == 3) {
      int p;
      cin >> p;
      op[i] = {{-1, 0, 2 * p},
               {0, 1, 0},
               {0, 0, 1}};
    } else {
      int p;
      cin >> p;
      op[i] = {{1, 0, 0},
               {0, -1, 2 * p},
               {0, 0, 1}};
    }
    op[i] = mat_mul(op[i], op[i - 1]);
  }  

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    auto res = mat_mul(op[a], points[--b]);
    cout << res[0][0] << " " << res[1][0] << endl;
  }
  return 0;
}
