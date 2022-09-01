#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  a.push_back(-(1LL << 60));
  a.push_back(1LL << 60);
  sort(a.begin(), a.end());
  
  int q;
  cin >> q;
  while (q--) {
    long long b;
    cin >> b;
    auto p1 = lower_bound(a.begin(), a.end(), b);
    auto p2 = p1;
    cout << min(abs(*p1 - b), abs(*--p2 - b)) << endl;
  }  
  return 0;
}
