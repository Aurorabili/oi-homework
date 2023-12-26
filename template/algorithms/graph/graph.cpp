#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define MAXN 100010
#define INF 0x3f3f3f3f

template <class T>
struct dsu {
  std::vector<T> p;

  explicit dsu(size_t n) : p(n) { std::iota(p.begin(), p.end(), 0); }

  T find(T x) { return x == p[x] ? x : p[x] = find(p[x]); }
  void unite(T x, T y) { p[find(x)] = find(y); }
};

struct edge {
  int u;
  int v;
  int w;

  bool operator<(const edge &e) const { return w < e.w; }
};

std::vector<edge> DAG[MAXN];

void dfs(const int u, std::vector<int> &visited) {
  visited[u] = 1;
  for (auto e : DAG[u]) {
    if (!visited[e.v]) {
      std::cout << e.v << ' ';
      dfs(e.v, visited);
    }
  }
}

void start_dfs(const int u, const int n) {
  std::cout << u << ' ';
  std::vector<int> visited(n, 0);
  dfs(u, visited);
  std::cout << '\n';
}

void bfs(const int u, const int n) {
  std::queue<int> q;
  std::vector<int> visited(n, 0);
  q.push(u);
  visited[u] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto e : DAG[u]) {
      if (!visited[e.v]) {
        visited[e.v] = 1;
        std::cout << e.v << ' ';
        q.push(e.v);
      }
    }
  }
}

int kruskal(const int n) {
  int mst = 0;
  dsu<int> d(n);

  auto cmp = [](const edge &e1, const edge &e2) { return e1.w > e2.w; };

  std::priority_queue<edge, std::vector<edge>, decltype(cmp)> pq(cmp);
  for (int u = 0; u < n; ++u) {
    for (auto e : DAG[u]) {
      pq.push(e);
    }
  }

  while (!pq.empty()) {
    edge e = pq.top();
    pq.pop();
    if (d.find(e.u) != d.find(e.v)) {
      d.unite(e.u, e.v);
      mst += e.w;
    }
  }

  return mst;
}

std::vector<int> dijsktra(const int u, const int n) {
  std::vector<int> dist(n, INF);
  std::priority_queue<std::pair<int, int>> pq;
  pq.push({0, u});
  dist[u] = 0;
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto e : DAG[u]) {
      if (dist[e.v] > dist[u] + e.w) {
        dist[e.v] = dist[u] + e.w;
        pq.push({dist[e.v], e.v});
      }
    }
  }
  return dist;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    DAG[u].push_back({u, v, w});
    DAG[v].push_back({v, u, w});
  }
  start_dfs(0, m);

  std::cout << "kruskal min = " << kruskal(m) << '\n';

  auto dist = dijsktra(0, m);
  std::cout << "dijsktra dist = ";
  for (int i = 0; i < n; ++i) {
    std::cout << dist[i] << ' ';
  }
}

/*

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 5 14
3 4 9
4 5 10
5 6 2
6 8 6
6 7 1
7 8 7

*/