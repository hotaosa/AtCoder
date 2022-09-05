#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int k;
  cin >> k;

  priority_queue<long long, vector<long long>, greater<> > pque;
  for (long long i = 1; i <= 9; ++i) pque.push(i);

  int cnt = 0;
  long long res = 0;
  while (cnt < k) {
    ++cnt;
    res = pque.top();
    pque.pop();
    for (int i = 0; i <= 9; ++i) {
      if (abs(i - (res % 10)) < 2) pque.push(res * 10 + i);
    }
  }

  cout << res << endl;
  return 0;
}
