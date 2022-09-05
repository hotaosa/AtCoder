#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  for (auto &p : a) { cin >> p; sum += p; }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= (sum + (4 * m) - 1) / (4 * m)) ++cnt;
  }

  cout << (cnt >= m ? "Yes" : "No" ) << endl;  
  return 0;
}
