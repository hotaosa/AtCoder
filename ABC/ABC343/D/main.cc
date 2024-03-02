#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n, t;
  cin >> n >> t;

  vector<ll> score(n, 0);
  map<ll, int> mp;
  mp[0] = n;

  int res = 1;
  while (t--) {
    int a;
    ll b;
    cin >> a >> b;
    if (--mp[score[--a]] == 0) --res;
    score[a] += b;
    if (++mp[score[a]] == 1) ++res;
    cout << res << endl;
  }

  return 0;
}