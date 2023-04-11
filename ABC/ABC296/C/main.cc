#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, x;
  cin >> n >> x;

  set<int> se;
  vector<int> a(n);
  for (auto &p : a) {
    cin >> p;
    se.insert(p);
  }

  bool exist = false;
  for (auto b : a) {
    exist |= se.count(b + x);
  }

  cout << (exist ? "Yes" : "No" ) << endl;
  return 0;
}
