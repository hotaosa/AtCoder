#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(n + 1, 4);
  cnt[0] = 0;
  for (int i = 0; i < n * 4 - 1; ++i) {
    int a;
    cin >> a;
    --cnt[a];
  }
  for (int i = 1; i <= n; ++i) if (cnt[i]) cout << i << endl;
  return 0;
}
