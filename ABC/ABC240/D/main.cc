#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  stack<pair<int, int> > st;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (st.empty() || st.top().first != a) {
      st.push(make_pair(a, 1));      
    } else {
      st.push(make_pair(a, st.top().second + 1));
      if (st.top().second == a) {
        for (int i = 0; i < a; ++i) st.pop();
      }
    }
    cout << st.size() << endl;
  }
  return 0;
}
