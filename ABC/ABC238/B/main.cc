#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> pos = {0, 360};
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cur = (cur + a) % 360;
    pos.push_back(cur);
  }
  sort(pos.begin(), pos.end());

  int res = 0;
  for (int i = 1; i < (int)pos.size(); ++i) res = max(res, pos[i] - pos[i - 1]);
  cout << res << endl;
  return 0;
}
