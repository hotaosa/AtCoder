#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    string t = s.substr(i, n - i);
    vector<int> lcp_len = atcoder::z_algorithm(t);
    for (int j = 1; j < n - i; ++j) if (j >= lcp_len[j]) res = max(res, lcp_len[j]);
  }
  cout << res << endl;  
  return 0;  
}
