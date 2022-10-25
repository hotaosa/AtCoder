#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> odd, even;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (i & 1) odd.push_back(a);
    else even.push_back(a);
  }

  vector<set<int> > dp_e(even.size());
  vector<set<int> > dp_o(odd.size() + 1);
  dp_e[0].insert(even[0]);
  dp_o[0].insert(0);

  for (int i = 1; i < (int)even.size(); ++i) {
    for (auto d : dp_e[i - 1]) {
      dp_e[i].insert(d + even[i]);
      dp_e[i].insert(d - even[i]);
    }
  }
  for (int i = 0; i < (int)odd.size(); ++i) {
    for (auto d : dp_o[i]) {
      dp_o[i + 1].insert(d + odd[i]);
      dp_o[i + 1].insert(d - odd[i]);
    }
  }

  if (dp_e.back().count(x) && dp_o.back().count(y)) cout << "Yes" << endl;
  else cout << "No" << endl;  
  return 0;
}
