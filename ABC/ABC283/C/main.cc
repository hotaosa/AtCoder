#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  stack<char> st;
  for (auto c : s) {
    if (c == '0' && st.top() == '0') {
      st.pop();
      st.push('x');
    } else {
      st.push(c);
    }
  }

  cout << st.size() << endl;  
  return 0;
}
