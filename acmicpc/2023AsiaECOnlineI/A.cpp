#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->ios::sync_with_stdio(false);
  auto hash = [](string s) -> int {
    int ret = 0;
    for (string::size_type i = 0; i < s.size(); ++i) {
      ret += (int)s[i] * (i + 1);
    }
    return ret;
  };
  int n, m, ca = 0, cb = 0;
  cin >> n >> m;
  vector<string> a, b, result;
  int vis[100 * (int)'Z'] = {0};
  for (int i = 1; i <= n; ++i) {
    string t;
    cin >> t;
    if (!vis[hash(t)]) {
      a.push_back(t);
      vis[hash(t)] = 1;
      ca++;
    }
  }
  for (int i = 0; i < 100 * (int)'Z'; ++i) vis[i] = 0;
  for (int i = 1; i <= m; ++i) {
    string t;
    cin >> t;
    if (!vis[hash(t)]) {
      b.push_back(t);
      vis[hash(t)] = 1;
      cb++;
    }
  }
  for (int i = 0; i < 100 * (int)'Z'; ++i) vis[i] = 0;
  for (int i = 0; i < max(ca, cb); ++i) {
    if (i < ca && !vis[hash(a[i])]) result.push_back(a[i]), vis[hash(a[i])] = 1;
    if (i < cb && !vis[hash(b[i])]) result.push_back(b[i]), vis[hash(b[i])] = 1;
  }
  for (auto &s : result) {
    cout << s << '\n';
  }
}