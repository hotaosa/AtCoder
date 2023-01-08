#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> vs(n);
  for (auto &p : vs) cin >> p;

  for (auto iter = vs.rbegin(); iter != vs.rend(); ++iter) {
    cout << *iter << endl;
  }
  
  return 0;
}
