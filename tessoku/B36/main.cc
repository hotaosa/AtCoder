#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  bitset<300000> s;
  cin >> s;
  cout << ((k + s.count()) & 1 ? "No" : "Yes") << endl;
  return 0;
}
