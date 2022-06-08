#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;
  map<int, long long> mp;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++mp[a];
  }

  long long res = n * (n - 1) * (n - 2) / 6;
  for (auto m : mp) {
    res -= m.second * (m.second - 1) * (m.second - 2) / 6;
    res -= m.second * (m.second - 1) / 2 * (n - m.second);    
  }
  cout << res << endl;
  return 0;
}
