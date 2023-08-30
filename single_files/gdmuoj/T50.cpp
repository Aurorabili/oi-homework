#include <iostream>

struct date {
  int year;
  int month;
  int day;
};

int main() {
  using namespace std;

  date d;
  cin >> d.year >> d.month >> d.day;
  const bool is_leap_year =
      (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0;
  const int days_of_month[12] = {
      31, is_leap_year ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days = 0;
  for (int i = 0; i < d.month - 1; i++) {
    days += days_of_month[i];
  }
  days += d.day;
  cout << days << endl;

  return 0;
}