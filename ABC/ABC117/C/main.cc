#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= m) { cout << "0" << endl; return 0; }
  vector<int> x(m);
  for (auto &p : x) cin >> p;
  sort(x.begin(), x.end());

  int sum = 0;
  vector<int> d;
  for (int i = 1; i < m; ++i) {
    d.push_back(x[i] - x[i - 1]);
    sum += x[i] - x[i - 1];
  }
  sort(d.rbegin(), d.rend());
  for (int i = 0; i < n - 1; ++i) sum -= d[i];
  cout << sum << endl;
  return 0;
}
