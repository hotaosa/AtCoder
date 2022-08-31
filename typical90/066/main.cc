#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) { cin >> l[i] >> r[i]; ++r[i]; }

  double res = 0.0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = l[i]; k < r[i]; ++k) {
        if (k <= l[j]) continue;        
        res += 1.0 / (r[i] - l[i]) * (min(r[j], k) - l[j]) / (r[j] - l[j]);
      }
    }
  }

  printf("%.10f\n", res);  
  return 0;
}
