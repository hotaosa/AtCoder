#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  prev_permutation(p.begin(), p.end());
  for (auto r : p) cout << r << endl;  
  return 0;
}
