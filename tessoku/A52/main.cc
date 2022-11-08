#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;

  queue<string> que;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      string s;
      cin >> s;
      que.push(s);
    } else if (t == 2) {
      cout << que.front() << endl;
    } else {
      que.pop();
    }
  }
  
  return 0;
}
