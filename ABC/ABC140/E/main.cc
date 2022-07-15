#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<long long, int> > vp;
  for (int i = 0; i < n; ++i) {
    long long p;
    cin >> p;
    vp.emplace_back(p, i);
  }
  sort(vp.rbegin(), vp.rend());

  multiset<int> se = {-1, -1, vp[0].second, n, n};
  long long res = 0;

  for (int i = 1; i < n; ++i) {
    long long p = vp[i].first;
    int id = vp[i].second;
    auto r1 = se.lower_bound(id);
    auto r2 = r1; ++r2;
    auto l1 = r1; --l1;
    auto l2 = l1; --l2;
    res += p * ((*l1 - *l2) * (*r1 - id) + (id - *l1) * (*r2 - *r1));
    se.insert(id);
  }

  cout << res << endl;  
  return 0;
}