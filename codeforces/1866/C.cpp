#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 100001
#define MOD 998244353

using namespace std;
using ll = long long;

template <const int T>
struct ModInt {
  const static int mod = T;
  int x;
  ModInt(int x = 0) : x(x % mod) {}
  ModInt(long long x) : x(int(x % mod)) {}
  int val() { return x; }
  ModInt operator+(const ModInt &a) const {
    int x0 = x + a.x;
    return ModInt(x0 < mod ? x0 : x0 - mod);
  }
  ModInt operator-(const ModInt &a) const {
    int x0 = x - a.x;
    return ModInt(x0 < 0 ? x0 + mod : x0);
  }
  ModInt operator*(const ModInt &a) const {
    return ModInt(1LL * x * a.x % mod);
  }
  ModInt operator/(const ModInt &a) const { return *this * a.inv(); }
  bool operator==(const ModInt &a) const { return x == a.x; };
  bool operator!=(const ModInt &a) const { return x != a.x; };
  void operator+=(const ModInt &a) {
    x += a.x;
    if (x >= mod) x -= mod;
  }
  void operator-=(const ModInt &a) {
    x -= a.x;
    if (x < 0) x += mod;
  }
  void operator*=(const ModInt &a) { x = 1LL * x * a.x % mod; }
  void operator/=(const ModInt &a) { *this = *this / a; }
  friend ModInt operator+(int y, const ModInt &a) {
    int x0 = y + a.x;
    return ModInt(x0 < mod ? x0 : x0 - mod);
  }
  friend ModInt operator-(int y, const ModInt &a) {
    int x0 = y - a.x;
    return ModInt(x0 < 0 ? x0 + mod : x0);
  }
  friend ModInt operator*(int y, const ModInt &a) {
    return ModInt(1LL * y * a.x % mod);
  }
  friend ModInt operator/(int y, const ModInt &a) { return ModInt(y) / a; }
  friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x; }
  friend istream &operator>>(istream &is, ModInt &t) { return is >> t.x; }

  ModInt pow(int64_t n) const {
    ModInt res(1), mul(x);
    while (n) {
      if (n & 1) res *= mul;
      mul *= mul;
      n >>= 1;
    }
    return res;
  }

  ModInt inv() const {
    int a = x, b = mod, u = 1, v = 0;
    while (b) {
      int t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if (u < 0) u += mod;
    return u;
  }
};

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    for (int j = 1; j <= a; ++j) {
      int x, y;
      cin >> x >> y;
      g[i].emplace_back(x, y);
    }
  }
  vector<int> visited(n + 1, 0);
  vector<int> z;
  ModInt<MOD> dp[MAX_N][3] = {0};
  auto dfs = [&](auto &&self, int u) -> void {
    if (visited[u]) {
      return;
    }

    visited[u]++;

    for (auto [v, w] : g[u]) {
      self(self, v);
      if (!w) {
        dp[u][2] += dp[u][1];
      }
      dp[u][w] += 1;
      dp[u][2] += dp[u][1] * dp[v][0];
      dp[u][0] += dp[v][0];
      dp[u][1] += dp[v][1];
      dp[u][2] += dp[v][2];
    }

    // visited[u]--;
  };
  dfs(dfs, 1);
  cout << dp[1][2] << endl;
}