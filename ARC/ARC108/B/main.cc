#include <iostream>
#include <string>
#include <stack>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::stack<char> st;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'x' && !st.empty()) {
      char t = st.top();
      if (t == 'o' && !st.empty()) {
        st.pop();
        t = st.top();
        if (t == 'f') st.pop();
        else { st.push('o'); st.push('x'); }        
      } else st.push('x');
    } else st.push(s[i]);
  }
  
  std::cout << st.size() << std::endl;
  return 0;
}
