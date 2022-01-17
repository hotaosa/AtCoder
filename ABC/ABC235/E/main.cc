#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
    int u, v, w, id;
    Edge(int u_, int v_, int w_, int id_) : u(u_), v(v_), w(w_), id(id_) { }
    bool operator<(const Edge &other) const { return w < other.w; }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<Edge> ve;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ve.push_back(Edge(--u, --v, w, -1));
    }
    for (int i = 0; i < q; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ve.push_back(Edge(--u, --v, w, i));
    }
    sort(ve.begin(), ve.end());
    vector<bool> res(q);
    atcoder::dsu uf(n);
    for (auto e : ve) {
        if (e.id == -1) uf.merge(e.u, e.v);
        else res[e.id] = !uf.same(e.u, e.v);
    }

    for (int i = 0; i < q; ++i) cout << (res[i] ? "Yes" : "No" ) << endl;
    return 0;
}
