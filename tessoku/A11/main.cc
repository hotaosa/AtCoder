#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  cout << lower_bound(a.begin(), a.end(), x) - a.begin() + 1 << endl;  
  return 0;
}
