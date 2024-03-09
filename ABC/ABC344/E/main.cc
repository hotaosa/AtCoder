#include <iostream>
#include <map>
#include <memory>

using namespace std;

struct Node {
  int v;
  shared_ptr<Node> pv, nx;
  Node(int v) : v(v), pv(nullptr), nx(nullptr) {}
};

int main() {
  int n;
  cin >> n;
  map<int, shared_ptr<Node> > mp;
  shared_ptr<Node> f = nullptr, e = nullptr;

  auto Connect = [](shared_ptr<Node> u, shared_ptr<Node> v) -> void {
    if (u->nx) {
      u->nx->pv = v;
      v->nx = u->nx;
    }
    u->nx = v;
    v->pv = u;
  };

  auto Erase = [&f](shared_ptr<Node> u) -> void {
    if (u->pv) {
      u->pv->nx = u->nx;
    } else {
      f = u->nx;
    }
    if (u->nx) {
      u->nx->pv = u->pv;
    }
  };

  while (n--) {
    int a;
    cin >> a;
    mp[a] = make_shared<Node>(a);
    if (!f) {
      f = mp[a];
    }
    if (e) {
      Connect(e, mp[a]);
    }
    e = mp[a];
  }

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      mp[y] = make_shared<Node>(y);
      Connect(mp[x], mp[y]);
    } else {
      int x;
      cin >> x;
      Erase(mp[x]);
    }
  }

  while (f) {
    cout << f->v << " ";
    f = f->nx;
  }
  cout << endl;

  return 0;
}