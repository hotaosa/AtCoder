#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  set<int> se;
  for (int i = 0; i < 5; ++i) {
    int a;
    cin >> a;
    se.insert(a);
  }
  cout << se.size() << endl;  
  return 0;
}
