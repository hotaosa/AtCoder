#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int s;
  cin >> s;

  set<int> se;
  se.insert(s);
  int cnt = 1;
  while (true) {
    ++cnt;
    if (s & 1) s = 3 * s + 1;
    else s /= 2;
    if (!se.insert(s).second) { cout << cnt << endl; return 0; }
  }  
  return 0;
}
