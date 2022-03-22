#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int inv(const vector<int> &v) {
  int ret = 0;
  int n = v.size();
  for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (v[j] > v[i]) ++ret;
  return ret;
}

int main() {
  map<char, int> ma;  
  for (int i = 0; i < 3; ++i) {
    char c;
    cin >> c;
    ma[c] = i;
  }

  vector<int> t(3);  
  for (int i = 0; i < 3; ++i) {
    char c;
    cin >> c;
    t[i] = ma[c];
  }

  cout << (inv(t) & 1 ? "No" : "Yes" ) << endl;
  return 0;
}
