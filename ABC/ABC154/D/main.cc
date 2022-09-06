#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> ex(n);
  for (int i = 0; i < n; ++i) {
    double p;
    cin >> p;
    ex[i] = (p + 1.) / 2.;
  }

  for (int i = 1; i < n; ++i) ex[i] += ex[i - 1];

  double res = ex[k - 1];
  for (int i = k; i < n; ++i) {
    res = max(res, ex[i] - ex[i - k]);
  }
  printf("%.10f\n", res);  
  return 0;
}
