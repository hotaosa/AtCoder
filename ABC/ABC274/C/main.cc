#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> res(2 * n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    res[i * 2 + 1] = res[i * 2 + 2] = res[--a] + 1;
  }

  for (auto &p : res) cout << p << endl;  
  return 0;
}
