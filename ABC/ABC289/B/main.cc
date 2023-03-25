#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<bool> exist(n, false);
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    exist[--a] = true;
  }

  stack<int> st;
  for (int i = 0; i < n; ++i) {
    if (!exist[i]) {
      cout << i + 1 << " ";
      while (!st.empty()) {
        cout << st.top() + 1 << " ";
        st.pop();
      }      
    } else {
      st.push(i);
    }
  }

  cout << endl;
  return 0;
}
