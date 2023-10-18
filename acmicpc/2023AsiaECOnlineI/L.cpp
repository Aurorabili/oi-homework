#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr), ios::sync_with_stdio(false);
  int n, m, k = 2;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    k = max(k, (int)ceil(t / (double)m));
  }
  cout << k;
}