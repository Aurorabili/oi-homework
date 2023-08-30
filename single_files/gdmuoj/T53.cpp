#include <algorithm>
#include <iostream>
#include <list>

struct Score {
  int id;
  int score;
};

int main() {
  using namespace std;

  int n, m;
  list<Score> scores;
  cin >> n >> m;

  for (int i = 0; i < n + m; ++i) {
    int id, score;
    cin >> id >> score;
    scores.push_back({id, score});
  }

  scores.sort(
      [](const Score &lhs, const Score &rhs) { return lhs.id < rhs.id; });

  for (const auto &score : scores) {
    cout << score.id << ' ' << score.score << endl;
  }
  return 0;
}