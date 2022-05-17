#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  a.push_back(0);
  a.push_back(0);
  n += 2;

  set<int> se;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int sum = a[i] + a[j] + a[k];
        if (sum <= w) se.insert(sum);
      }
    }
  }
  cout << se.size() << endl;
  return 0;
}
