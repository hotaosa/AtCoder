#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int cnt = 0, res = 0;
  for (int i = 2; i <= 1000; ++i) {
    int cur = 0;
    for (auto ai : a) if (ai % i == 0) ++cur;
    if (cur > cnt) {
      res = i;
      cnt = cur;
    }
  }

  cout << res << endl;  
  return 0;
}
