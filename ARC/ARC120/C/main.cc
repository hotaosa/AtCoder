#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) { cin >> a[i]; a[i] += i; }
  for (int i = 0; i < n; ++i) { cin >> b[i]; b[i] += i; }

  bool same = true;
  vector<int> aa = a, bb = b;
  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());
  for (int i = 0; i < n; ++i) same &= aa[i] == bb[i];
  if (!same) { cout << "-1" << endl; return 0; }
  
  atcoder::fenwick_tree<int> bit(n);
  map<int, queue<int> > mq;
  for (int i = 0; i < n; ++i) mq[a[i]].push(i);

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int pos = mq[b[i]].front();    
    mq[b[i]].pop();
    int offset = bit.sum(pos + 1, n);    
    res += pos + offset - i;
    bit.add(pos, 1);    
  }

  cout << res << endl;
  return 0;
}
