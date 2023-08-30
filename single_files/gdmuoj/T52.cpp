#include <algorithm>
#include <iomanip>
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

  double average() const { return (score_a_ + score_b_ + score_c_) / 3.0; }

 private:
  std::string id_;
  std::string name_;
  int score_a_;
  int score_b_;
  int score_c_;
};

class Students {
 public:
  Students() = default;
  Students(const std::vector<Student> &students) : students_(students) {}

  void add(const Student &student) { students_.push_back(student); }

  const Student &high() const {
    return *std::max_element(students_.begin(), students_.end(),
                             [](const Student &lhs, const Student &rhs) {
                               return lhs.average() < rhs.average();
                             });
  }

  double average_score_a() const {
    double sum = 0;
    for (const auto &student : students_) {
      sum += student.score_a();
    }
    return sum / students_.size();
  }

  double average_score_b() const {
    double sum = 0;
    for (const auto &student : students_) {
      sum += student.score_b();
    }
    return sum / students_.size();
  }

  double average_score_c() const {
    double sum = 0;
    for (const auto &student : students_) {
      sum += student.score_c();
    }
    return sum / students_.size();
  }

 private:
  std::vector<Student> students_;
};

int main() {
  using namespace std;

  int n;
  cin >> n;
  Students students;
  for (int i = 0; i < n; ++i) {
    string id, name;
    int score_a, score_b, score_c;
    cin >> id >> name >> score_a >> score_b >> score_c;
    students.add(Student(id, name, score_a, score_b, score_c));
  }

  cout << students.average_score_a() << ' ' << students.average_score_b() << ' '
       << students.average_score_c() << endl;
  cout << students.high().id() << ' ' << students.high().name() << ' '
       << students.high().score_a() << ' ' << students.high().score_b() << ' '
       << students.high().score_c() << endl;

  return 0;
}