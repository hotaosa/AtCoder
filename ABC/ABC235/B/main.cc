#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &p : h) cin >> p;
    int res = 0;
    while (res < n - 1 && h[res] < h[res + 1]) ++res;
    cout << h[res] << endl;
    return 0;
}
