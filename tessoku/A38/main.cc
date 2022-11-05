#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int d, n;
  cin >> d >> n;
  vector<int> res(d, 24);
  for (int i = 0; i < n; ++i) {
    int l, r, h;
    cin >> l >> r >> h;    
    for (int j = --l; j < r; ++j) res[j] = min(res[j], h);
  }

  int sum = 0;
  for (auto r : res) sum += r;
  cout << sum << endl;  
  return 0;
}
