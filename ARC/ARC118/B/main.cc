#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int k;
    long long n, m;
    std::cin >> k >> n >> m;

    std::vector<long long> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; ++i) std::cin >> a[i];
    for (int i = 1; i <= k; ++i) b[i] = m * a[i] / n;

    long long mm = m;
    std::vector<std::pair<long long, int> > vp;
    for (int i = 1; i <= k; ++i) {
        mm -= b[i];
        long long d = m * a[i] - n * b[i];
        vp.push_back(std::make_pair(d, i));
    }

    std::sort(vp.begin(), vp.end(), std::greater<>());
    for (int i = 0; i < mm; ++i) ++b[vp[i].second];
    for (int i = 1; i <= k; ++i) std::cout << b[i] << " ";
    std::cout << std::endl;    
    return 0;
}
