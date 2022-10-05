#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  long long cur = n;
  vector<long long> res = {n};
  while (cur) {
    cur = n & (cur - 1);
    res.push_back(cur);
  }
  reverse(res.begin(), res.end());
  for (auto &p : res) cout << p << endl;  
  return 0;
}
