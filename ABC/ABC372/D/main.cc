#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &e : h) cin >> e;

  vector<int> res(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; --i) {
    res[i] = size(st);
    while (!empty(st) && st.top() < h[i]) st.pop();
    st.push(h[i]);
  }

  for (auto r : res) cout << r << " ";
  cout << endl;

  return 0;
}