#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, long long> ma;
  for (auto &p : a) { cin >> p; ++ma[p]; }
  
  set<int> se;
  long long res = 0;
  for (auto ai : a) {
    if (!se.insert(ai).second) continue;
    for (int x = 1; x * x <= ai; ++x) {
      if (ai % x == 0) {
        int y = ai / x;        
        res += ma[ai] * ma[x] * ma[y] * (x != y ? 2 : 1);
      }
    }
  }
  cout << res << endl;
  return 0;
}
