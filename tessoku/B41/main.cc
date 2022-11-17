#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  vector<pair<int, int> > res;
  while (max(x, y) > 1) {
    res.emplace_back(x, y);
    if (x > y) x -= y;
    else y -= x;    
  }
  
  cout << res.size() << endl;
  for (auto it = res.rbegin(); it != res.rend(); ++it) cout << it->first << " " << it->second << endl;
  return 0;
}
