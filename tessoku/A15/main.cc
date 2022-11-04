#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int cnt= 0;
  for (auto &p : mem) p.second = ++cnt;
  for (auto &p : v) p = mem[p];  
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  vcomp(a);
  for (auto &p : a) cout << p << " ";
  cout << endl;  
  return 0;
}
