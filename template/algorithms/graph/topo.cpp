#include <iostream>
#include <queue>
#include <vector>
#define MAXN 100010
#define INF 0x3f3f3f3f

struct edge {
  int u;
  int v;
};

std::vector<edge> DAG[MAXN];
int in_dist[MAXN] = {0};

std::vector<int> topo(int n) {
  std::vector<int> res;
  std::queue<int> q;
  for (int i = 0; i < n; ++i)
    if (in_dist[i] == 0) q.push(i);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    res.push_back(u);
    for (auto e : DAG[u])
      if (--in_dist[e.v] == 0) q.push(e.v);
  }

  if ((int)res.size() != n) res.clear();
  return res;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    DAG[u].push_back({u, v});
    in_dist[v]++;
  }

  std::vector<int> res = topo(n);
  if (res.empty())
    std::cout << "No solution" << std::endl;
  else
    for (auto u : res) std::cout << u << " ";
}
