#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> res(n, m);
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    --res[--a];
  }

  for (auto r : res) cout << r << endl;  
  return 0;
}
