#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int q;
  cin >> q;
  
  stack<string> st;  
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      string s;
      cin >> s;
      st.push(s);
    } else if (t == 2) {
      cout << st.top() << endl;
    } else {
      st.pop();
    }
  }
  
  return 0;
}
