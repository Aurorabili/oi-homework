#include <iostream>
#include <string>
#include <vector>

class Student {
 public:
  Student() = default;
  Student(const std::string &id, const std::string &name, int score_a,
          int score_b, int score_c)
      : id_(id),
        name_(name),
        score_a_(score_a),
        score_b_(score_b),
        score_c_(score_c) {}

  const std::string &id() const { return id_; }
  const std::string &name() const { return name_; }
  const int &score_a() const { return score_a_; }
  const int &score_b() const { return score_b_; }
  const int &score_c() const { return score_c_; }

 private:
  std::string id_;
  std::string name_;
  int score_a_;
  int score_b_;
  int score_c_;
};

int main() {
  using namespace std;

  int n;
  cin >> n;
  vector<Student> students;
  for (int i = 0; i < n; i++) {
    string id, name;
    int score_a, score_b, score_c;
    cin >> id >> name >> score_a >> score_b >> score_c;
    students.emplace_back(id, name, score_a, score_b, score_c);
  }

  for (const auto &student : students) {
    cout << student.id() << "," << student.name() << "," << student.score_a()
         << "," << student.score_b() << "," << student.score_c() << endl;
  }
  return 0;
}