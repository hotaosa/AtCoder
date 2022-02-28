#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  vector<int> nx(10);
  for (auto &p : nx) cin >> p;
  cout << nx[nx[nx[0]]] << endl;
  return 0;
}
