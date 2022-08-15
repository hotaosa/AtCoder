#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool is_prime(int k) {
  for (int i = 2; i * i <= k; ++i) if (k % i == 0) return false;
  return true;
}

long long solve(vector<int> &a, vector<long long> &b) {
  int n = a.size();
  atcoder::mf_graph<long long> graph(n + 2);
  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) {
      graph.add_edge(n, i, b[i]);
    } else {
      graph.add_edge(i, n + 1, b[i]);
    }    
  }
  for (int i = 0; i < n; ++i) {
    if (!(a[i] & 1)) continue;
    for (int j = 0; j < n; ++j) {
      if (a[j] & 1) continue;
      if (is_prime(a[i] + a[j])) graph.add_edge(i, j, b[j]);
    }
  }
  return graph.flow(n, n + 1);
}

int main() {
  int n;
  cin >> n;

  vector<int> a;
  vector<long long> b;
  long long cnt_one = 0;
  for (int i = 0; i < n; ++i) {
    int ai;
    long long bi;
    cin >> ai >> bi;
    if (ai == 1) cnt_one += bi;
    else {
      a.push_back(ai);
      b.push_back(bi);
    }
  }

  long long flow1 = solve(a, b);
  a.push_back(1);
  b.push_back(cnt_one);
  long long flow2 = solve(a, b);
  flow2 += (cnt_one - (flow2 - flow1)) / 2;
  cout << flow2 << endl;  
  return 0;
}
