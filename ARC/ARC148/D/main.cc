#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  n <<= 1;
  
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    mp[a] ^= 1;
  }

  if (m & 1) {
    for (auto p : mp) if (p.second) { cout << "Alice" << endl; return 0; }
    cout << "Bob" << endl;
    return 0;
  } else {
    int cnt = 0;
    for (auto p : mp) {
      if (!p.second) continue;
      if (mp[p.first + m / 2]) {
        ++cnt;
        mp[p.first + m / 2] = 0;
      } else {
        cout << "Alice" << endl;
        return 0;
      }
    }
    cout << (cnt & 1 ? "Alice" : "Bob") << endl;
  }  
  return 0;
}
