#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    long long n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    
    for (int i = 0; i <= q - p; ++i) {
        for (int j = 0; j <= s - r; ++j) {
            if ((i + p) - a == (j + r) - b) {                
                long long k = (i + p) - a;
                if (max(1 - a, 1 - b) <= k && k <= min(n - a, n - b)) { cout << '#'; continue; }                                                
            } else if ((i + p) - a == b - (j + r)) {
                long long k = (i + p) - a;
                if (max(1 - a, b - n) <= k && k <= min(n - a, b - 1)) { cout << '#'; continue; }
            }
            cout << '.';
        }
        cout << endl;
    }
    return 0;
}
