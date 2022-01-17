#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n / 100, b = (n / 10) % 10, c = n % 10;
    cout << 111 * (a + b + c) << endl;
    return 0;
}
