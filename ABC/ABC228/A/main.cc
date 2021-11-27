#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int s, t, x;
    std::cin >> s >> t >> x;
    if (t < s) t += 24;
    if (x < s) x += 24;
    std::cout << (x >= s && x < t ? "Yes" : "No" ) << std::endl;
    return 0;
}
