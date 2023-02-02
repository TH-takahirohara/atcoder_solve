#include <bits/stdc++.h>
using namespace std;

void make_kousi(vector<pair<int, int>> &vec, int x, int y) {
  vec.at(0) = make_pair(x+1, y+2);
  vec.at(1) = make_pair(x+2, y+1);
  vec.at(2) = make_pair(x+2, y-1);
  vec.at(3) = make_pair(x+1, y-2);
  vec.at(4) = make_pair(x-1, y-2);
  vec.at(5) = make_pair(x-2, y-1);
  vec.at(6) = make_pair(x-2, y+1);
  vec.at(7) = make_pair(x-1, y+2);
}

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  
  vector<pair<int, int>> first_vec(8);
  vector<pair<int, int>> second_vec(8);
  
  make_kousi(first_vec, x1, y1);
  make_kousi(second_vec, x2, y2);
  
  for (auto p1 : first_vec) {
    for (auto p2 : second_vec) {
      if (p1 == p2) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
