#include <iostream>
#include <vector>
#include <map>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint;

int main() {
  int n, k;
  cin >> n >> k;
  mint::set_mod(k);
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  vector<mint> sum(n + 1, 0);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i - 1];
  
  map<int, int> mp;
  long long res = 0;  
  for (int i = 0; i <= n; ++i) {
    sum[i] -= i;
    if (i >= k) --mp[sum[i - k].val()];
    res += mp[sum[i].val()]++;        
  }  
  cout << res << endl;    
  return 0;
}