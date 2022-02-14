#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;  
  vector<int> a(n);
  long long res = 0;
  for (auto &p : a) { cin >> p; res += p; }

  vector<int> cnt(31, 0);
  for (auto ai : a) {
    for (int i = 0; i < 31; ++i) {
      if (ai & (1 << i)) ++cnt[i];
    }
  }

  for (int i = 0; i < n; ++i) {    
    long long cur = 0;
    for (int j = 0; j < 31; ++j) {      
      if (a[i] & (1 << j)) cur += (1LL << j) * (n - cnt[j]);        
      else cur += (1LL << j) * cnt[j];
    }
    res = max(res, cur);
  }

  cout << res << endl;
  return 0;
}
