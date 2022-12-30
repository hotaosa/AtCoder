#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  sort(a.rbegin(), a.rend());
  cout << a[0] + a[1] << endl;  
  return 0;
}
