#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long res = 0, k = floor(sqrt(n));
    for (long long i = 1; i <= k; ++i) res += i * (n / i - (n / (i + 1)));
    for (long long i = 1; i <= n / (k + 1); ++i) res += n / i;

    cout << res << endl;
    return 0;
}
