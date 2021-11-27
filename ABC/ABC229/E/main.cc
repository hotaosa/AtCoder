#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int> > graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (--u > --v) std::swap(u, v);
        graph[u].push_back(v);
    }

    atcoder::dsu uf(n);
    std::vector<int> res = {0};
    int cur = 0;
    for (int v = n - 1; v > 0; --v) {
        ++cur;
        for (int nv : graph[v]) {
            if (!uf.same(v, nv)) {
                --cur;
                uf.merge(v, nv);
            }
        }
        res.push_back(cur);
    }

    for (auto iter = res.rbegin(); iter != res.rend(); ++iter) std::cout << *iter << std::endl;
    return 0;
}
