#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  set <int> se;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (!se.insert(a).second) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;  
  return 0;
}
