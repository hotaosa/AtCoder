#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<atcoder::modint998244353> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

    atcoder::dsu uf_r(n), uf_c(n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool swappable_r = true, swappable_c = true;
            for (int l = 0; l < n; ++l) {
                if (a[i][l] + a[j][l] > k) swappable_r = false;
                if (a[l][i] + a[l][j] > k) swappable_c = false;
            }
            if (swappable_r) uf_r.merge(i, j);
            if (swappable_c) uf_c.merge(i, j);
        }
    }

    atcoder::modint998244353 res = 1;
    for (int i = 0; i < n; ++i) {
        if (uf_r.leader(i) == i) res *= fact[uf_r.size(i)];
        if (uf_c.leader(i) == i) res *= fact[uf_c.size(i)];
    }

    cout << res.val() << endl;
    return 0;
}
