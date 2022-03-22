#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string t;
  cin >> n >> t;
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, -1, 0, 1};

  int x = 0, y = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] == 'S') {
      x += dx[cur];
      y += dy[cur];
    } else cur = (cur + 1) % 4;
  }

  cout << x << " " << y << endl;
  return 0;
}
