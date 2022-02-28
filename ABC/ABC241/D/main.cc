#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

int main() {
  multiset<long long> se;
  for (int i = 0; i < 5; ++i) {se.insert(-1); se.insert(INF); } 

  int q;
  cin >> q;

  while (q--) {
    int qu;
    long long x;
    cin >> qu >> x;
    if (qu == 1) {
      se.insert(x);
    } else if (qu == 2) {
      int k;
      cin >> k;
      auto p = se.upper_bound(x);      
      for (int i = 0; i < k; ++i) --p;
      cout << *p << endl;
    } else {
      int k;
      cin >> k;
      auto p = se.lower_bound(x);
      for (int i = 0; i < k - 1; ++i) ++p;
      cout << (*p < INF ? *p : -1) << endl;
    }
  }
  return 0;
}
