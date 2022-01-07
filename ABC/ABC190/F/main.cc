#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &p : a) cin >> p;

    atcoder::fenwick_tree<int> bit(n);
    long long res = 0LL;

    for (int i = 0; i < n; ++i) {
        res += i - bit.sum(0, a[i]);
        bit.add(a[i], 1);
    }
    
    cout << res << endl;
    for (int i = 0; i < n - 1; ++i) {
        res += n - 1 - 2 * a[i];
        cout << res << endl;
    }    
    return 0;
}