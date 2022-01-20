#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> x(n);
  for (int i = 0; i < n; ++i) x[i] = s[i] - '0';  
  for (int i = 1; i < n; ++i) x[i] += x[i - 1];  

  vector<int> res;
  for (int i = n - 1; i >= 0; --i) {
    res.push_back(x[i] % 10);
    if (i > 0) x[i - 1] += x[i] / 10;
    else if (x[i] >= 10) res.push_back(x[i] / 10);
  }
  
  for (int i = (int)res.size() - 1; i >= 0; --i) cout << res[i];
  cout << endl;
  return 0;
}
