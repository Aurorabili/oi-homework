#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a, b;
  set<string> vis;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (vis.find(s) == vis.end()) {
      a.push_back(s);
      vis.insert(s);
    }
  }
  vis.clear();
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    if (vis.find(s) == vis.end()) {
      b.push_back(s);
      vis.insert(s);
    }
  }
  vis.clear();
  vector<string> ans;
  for (string::size_type i = 0; i < max(a.size(), b.size()); ++i) {
    if (i < a.size() && vis.find(a[i]) == vis.end()) {
      ans.push_back(a[i]);
      vis.insert(a[i]);
    }
    if (i < b.size() && vis.find(b[i]) == vis.end()) {
      ans.push_back(b[i]);
      vis.insert(b[i]);
    }
  }
  for (auto s : ans) cout << s << '\n';
}