#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  stack<char> st;
  vector<bool> used(26, false);

  bool possible = true;
  for (auto c : s) {
    if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      while (st.top() != '(') {
        used[st.top() - 'a'] = false;
        st.pop();
      }
      st.pop();
    } else {
      if (used[c - 'a']) {
        possible = false;
      } else {
        used[c - 'a'] = true;
        st.push(c);
      }
    }
  }

  cout << (possible ? "Yes" : "No" ) << endl;  
  return 0;
}
