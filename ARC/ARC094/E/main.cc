#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  constexpr long long INF = 1LL << 60;
  int n;
  cin >> n;
  long long sum = 0, mi = INF;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    sum += a;
    if (b < a) mi = min(mi, b);    
  }  
  cout << (mi != INF ? sum - mi : 0LL) << endl;
  return 0;
}
