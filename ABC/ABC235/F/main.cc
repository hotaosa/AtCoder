#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
    string s;
    int m;
    cin >> s >> m;
    int n = s.length();
    int need = 0;
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        need |= (1 << c);        
    }

    vector<vector<vector<mint> > > sum(n + 1, vector<vector<mint> > (2, vector<mint>(1 << 10, 0)));
    vector<vector<vector<mint> > > cnt(n + 1, vector<vector<mint> > (2, vector<mint>(1 << 10, 0)));    
    cnt[0][0][0] = 1;

    for (int i = 0; i < n; ++i) {        
        for (int use = 0; use < (1 << 10); ++use) {            
            for (int nx = 0; nx <= 9; ++nx) {
                if (use == 0 && nx == 0) { cnt[i + 1][1][0] = 1; continue; }
                cnt[i + 1][1][use | (1 << nx)] += cnt[i][1][use];
                sum[i + 1][1][use | (1 << nx)] += sum[i][1][use] * 10 + cnt[i][1][use] * nx;
                if (nx < s[i] - '0') {
                    cnt[i + 1][1][use | (1 << nx)] += cnt[i][0][use];
                    sum[i + 1][1][use | (1 << nx)] += sum[i][0][use] * 10 + cnt[i][0][use] * nx;
                } else if (nx == s[i] - '0') {
                    cnt[i + 1][0][use | (1 << nx)] += cnt[i][0][use];
                    sum[i + 1][0][use | (1 << nx)] += sum[i][0][use] * 10 + cnt[i][0][use] * nx;
                }
            }
        }
    }

    mint res = 0;
    for (int i = 0; i < (1 << 10); ++i) if ((need & i) == need) res += sum[n][0][i] + sum[n][1][i];
    cout << res.val() << endl;    
    return 0;
}