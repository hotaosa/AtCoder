#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  bool exist = false;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        exist |= (a[i] + a[j] + a[k] == 1000);
      }
    }
  }

  cout << (exist ? "Yes" : "No") << endl;  
  return 0;
}
