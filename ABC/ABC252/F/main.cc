#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long l;
  cin >> n >> l;
  
  priority_queue<long long, vector<long long>, greater<> > pque;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    pque.push(a);
    l -= a;
  }
  if (l > 0) pque.push(l);

  long long res = 0;
  while (pque.size() > 1) {
    long long a1 = pque.top();
    pque.pop();
    long long a2 = pque.top();
    pque.pop();
    res += a1 + a2;
    pque.push(a1 + a2);
  }

  cout << res << endl;
  return 0;
}
