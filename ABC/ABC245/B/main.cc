#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  set<int> se;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    se.insert(a);
  }
  int res = 0;
  while (se.count(res)) ++res;
  cout << res << endl;
  return 0;
}
