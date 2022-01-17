#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    map<int, vector<int> > ma;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ma[a].push_back(i + 1);
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        if (ma[x].size() < k) cout << "-1" << endl;
        else cout << ma[x][k - 1] << endl;
    }
    return 0;
}
