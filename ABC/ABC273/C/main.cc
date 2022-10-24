#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++mp[-a];
  }

  vector<int> res(n, 0);
  int cnt = 0;
  for (auto m : mp) {
    res[cnt++] = m.second;
  }

  for (auto &p : res) cout << p << endl;  
  return 0;
}
