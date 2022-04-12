#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void func(string cur, int sum, const int len, set<string> &res) {
  if ((int)cur.length() == len) {
    if (sum == 0) res.insert(cur);
    return;
  }
  func(cur + "(", sum + 1, len, res);
  if (sum > 0) func(cur + ")", sum - 1, len, res);
}

int main() {
  int n;
  cin >> n;
  set<string> res;
  func("", 0, n, res);
  for (auto r : res) cout << r << endl;
  return 0;
}
