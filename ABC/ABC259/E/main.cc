#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int> > > prime_factor(n);
  map<int, pair<int, bool> > mp;

  auto Update = [&](int p, int e) -> void {
    if (e == mp[p].first) mp[p].second = false;
    if (e > mp[p].first) mp[p] = {e, true};
  };

  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    while (m--) {
      int p, e;
      cin >> p >> e;
      Update(p, e);
      prime_factor[i].emplace_back(p, e);
    }
  }

  int res = 1;  
  for (int i = 0; i < n; ++i) {
    bool is_unique = false;
    for (auto pa : prime_factor[i]) {
      int p = pa.first, e = pa.second;
      is_unique |= (e == mp[p].first && mp[p].second);      
    }
    if (is_unique) ++res;    
  }
  cout << min(n, res) << endl;
  return 0;
}