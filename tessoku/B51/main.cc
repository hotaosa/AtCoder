#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  stack<int> st;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      int r = i + 1, l = st.top() + 1;
      st.pop();
      cout << l << " " << r << endl;
    }    
  }
  
  return 0;
}
