#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, h, w;
  cin >> n >> h >> w;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    res ^= --a;
    res ^= --b;
  }

  cout << (res ? "First" : "Second") << endl;
  return 0;
}
