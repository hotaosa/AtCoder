#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int mx = 0;
  for (auto &p : a) { cin >> p; mx = max(mx, p); }
  for (int i = 0; i < k; ++i) {
    int b;
    cin >> b;
    if (a[--b] == mx) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}
