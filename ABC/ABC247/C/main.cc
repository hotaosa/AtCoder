#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

vector<int> func(int n) {
  if (n == 1) return vector<int>(1, 1);  
  vector<int> child = func(n - 1);
  vector<int> ret = child;
  ret.push_back(n);
  ret.insert(ret.end(), child.begin(), child.end());
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> res = func(n);  
  for (auto &p : res) cout << p << " ";
  cout << endl;  
  return 0;
}
