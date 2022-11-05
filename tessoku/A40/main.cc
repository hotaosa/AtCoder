#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  unordered_map<int, long long> mp;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++mp[a];
  }

  long long res = 0;
  for (auto m : mp) {
    res += m.second * (m.second - 1) * (m.second - 2) / 6;
  }

  cout << res << endl;  
  return 0;
}
