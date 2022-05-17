#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> p(n);
  for (auto &pp : p) cin >> pp;

  long long res = 0;
  multiset<long long> se;  

  for (int i = 0; i < n; ++i) {
    if (se.empty() || p[i] <= *se.begin()) se.insert(p[i]);    
    else {
     res += p[i] - *se.begin();
     se.erase(se.begin());
     se.insert(p[i]);
     se.insert(p[i]);
    }
  }

  cout << res << endl;
  return 0;
}
