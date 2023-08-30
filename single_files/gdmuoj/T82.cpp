#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool pour(int step, vector<int> &bottles, int bottle_a, int bottle_b,
          int bottle_c) {
  switch (step) {
    case 0: {  // a -> b
      if (bottles[1] != 0) return false;
      bottles[0] -= bottle_b;
      bottles[1] += bottle_b;
      break;
    }
    case 1: {  // b -> c
      int _t = min(bottle_c - bottles[2], bottles[1]);
      bottles[1] -= _t;
      bottles[2] += _t;
      break;
    }
    case 2: {  // c -> a
      if (bottles[2] != bottle_c) return false;
      int _t = min(bottle_a - bottles[0], bottle_c);
      bottles[2] -= _t;
      bottles[0] += _t;
      break;
    }
  }
  return true;
}

void output(int step, vector<int> &bottles) {
  cout << "   <" << step << ">   |" << setw(5) << bottles[0] << setw(5)
       << bottles[1] << setw(5) << bottles[2] << endl;
}

int main() {
  int bottle_a, bottle_b, bottle_c, n;
  cin >> bottle_a >> bottle_b >> bottle_c >> n;

  cout << " >> The division steps are as follows." << endl;
  cout << endl;
  cout << " Bottle:    a<" << bottle_a << "> b<" << bottle_b << "> c<"
       << bottle_c << ">" << endl;
  cout << "-----------------------------\n Step No.|" << endl;

  vector<int> bottles = {bottle_a, 0, 0};

  int step = 0, r_step = 0;
  output(r_step, bottles);
  while (bottles[0] != n && bottles[1] != n && bottles[2] != n) {
    if (pour(step % 3, bottles, bottle_a, bottle_b, bottle_c)) {
      r_step++;
      output(r_step, bottles);
    }
    step++;
  }
  return 0;
}