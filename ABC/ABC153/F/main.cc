#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long d, a;  
  cin >> n >> d >> a;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<> > pque;
  
  for (int i = 0; i < n; ++i) {    
    long long x, h;
    cin >> x >> h;
    pque.emplace(x, h);
  }
  
  long long res = 0, add = 0;
  while (!pque.empty()) {
    long long x = pque.top().first;
    long long h = pque.top().second;
    pque.pop();    
    if (h > add) {
      h -= add;
      long long cnt = (h + a - 1) / a;
      res += cnt;
      add += a * cnt;
      pque.emplace(x + d * 2 + 1, -a * cnt);
    } else if (h < 0LL) {
      add += h;
    }
  }
  cout << res << endl;  
  return 0;
}
