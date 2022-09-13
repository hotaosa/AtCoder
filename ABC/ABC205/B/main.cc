#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());

  for (int i = 0; i < n; ++i) {
    if (a[i] != i + 1) { cout << "No" << endl; return 0; }
  }
  cout << "Yes" << endl;  
  return 0;
}
