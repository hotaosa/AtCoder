#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  queue<int> que;
  vector<int> v(n);

  que.push(0);
  que.push(n - 1);
  v[0] = v[n - 1] = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'B' && s[i + 1] == 'A') {
      v[i + 1] = 1;
      que.push(i + 1);
    }
  }
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    if (p + 1 < n && s[p] == 'A') {
      v[p + 1] = v[p] + 1;
      que.push(p + 1);
    }
    if (p > 0 && s[p - 1] == 'B') {
      v[p - 1] = v[p] + 1;
      que.push(p - 1);
    }
  }

  int res = 0;
  for (auto r : v) res += r;
  cout << res << endl;  
  return 0;
}
