#include <iostream>
#include <vector>
//
#include <atcoder/lazysegtree>

using namespace std;

int Operate(int a, int b) { return max(a, b); }
int E() { return 0; }
int Map(int a, int b) { return max(a, b); }
int Composite(int a, int b) { return max(a, b); }
int Id() { return 0; }
using LazySegtree =
    atcoder::lazy_segtree<int, Operate, E, int, Map, Composite, Id>;

int main() {
  int w, n;
  cin >> w >> n;

  LazySegtree seg(w);
  while (n--) {
    int l, r;
    cin >> l >> r;
    int h = seg.prod(--l, r) + 1;
    cout << h << endl;
    seg.apply(l, r, h);
  }

  return 0;
}