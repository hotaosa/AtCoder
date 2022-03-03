#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  vector<pair<long long, long long> > ld, ru;
  
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ld.push_back(make_pair(min(x[i], x[j]), min(y[i], y[j])));
      ru.push_back(make_pair(max(x[i], x[j]), max(y[i], y[j])));
    }
  }

  long long res = 0;
  for (int i = 0; i < (int)ld.size(); ++i) {
    for (int j = 0; j < (int)ru.size(); ++j) {
      int cnt = 0;
      for (int k = 0; k < n; ++k) {
        if (x[k] >= ld[i].first && x[k] <= ru[j].first && y[k] >= ld[i].second && y[k] <= ru[j].second) ++cnt;
      }
      if (cnt >= k) {
        if (res == 0) res = (ru[j].first - ld[i].first) * (ru[j].second - ld[i].second);
        else res = min(res, (ru[j].first - ld[i].first) * (ru[j].second - ld[i].second));
      }
    }    
  }
  cout << res << endl;  
  return 0;
}
