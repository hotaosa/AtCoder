#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;

  priority_queue<int, vector<int>, greater<> > pque;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v;
      cin >> v;
      pque.push(v);
    } else if (t == 2) {
      cout << pque.top() << endl;
    } else {
      pque.pop();
    }
  }
  
  return 0;
}
