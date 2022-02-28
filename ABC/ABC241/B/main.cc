#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> ma;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++ma[a];
  }
  for (int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    if (!ma[b]--) { cout << "No" << endl; return 0; }
  }
  cout << "Yes" << endl;  
  return 0;
}
