#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());

  deque<int> dq;
  for (int ai : a) dq.push_back(ai);

  int res = 0;
  while (dq.size() > 1) {
    ++res;
    int b = dq.back();
    dq.pop_back();
    if (b % dq.front()) dq.push_front(b % dq.front());
  }

  cout << res << endl;  
  return 0;
}
