#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> keys(m);
  vector<bool> opened;

  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    for (int j = 0; j < c; ++j) {
      int a;
      cin >> a;
      keys[i].emplace_back(--a);
    }
    char r;
    cin >> r;
    opened.emplace_back(r == 'o');
  }

  int res = 0;
  for (int b = 0; b < (1 << n); ++b) {
    bool valid = true;
    for (int i = 0; valid && i < m; ++i) {
      int cnt = 0;
      for (int key : keys[i]) {
        if (b >> key & 1) ++cnt;
      }
      valid &= (opened[i] == (cnt >= k));
    }
    if (valid) {
      ++res;
    }
  }

  cout << res << endl;
  return 0;
}