#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &p : d) cin >> p;
  sort(d.begin(), d.end());

  int a = d[n / 2], b = d[n / 2 - 1];
  cout << a - b << endl;
  return 0;
}
