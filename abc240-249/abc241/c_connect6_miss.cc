#include <bits/stdc++.h>
using namespace std;

// row: 行, col: 列
bool check(vector<string> &data, int N, int row, int col) {
  vector<vector<int>> dirs;
  dirs = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
  
  for (vector<int> dir : dirs) {
    int sum = 0;
    
    for (int i=0; i<6; i++) {
      int row_tmp = row + dir.at(0) * i;
      int col_tmp = col + dir.at(1) * i;
      
      if (row_tmp < 0 || row_tmp >= N || col_tmp < 0 || col_tmp >= N) {
        continue;
      }
      
      if (data.at(row_tmp).at(col_tmp) == '#') {
        sum += 1;
      }
    }
    
    if (sum >= 4) {
      return true;
    }
  }
  
  return false;
}

int main() {
  int N;
  cin >> N;
  
  vector<string> data(N);
  for (int i=0; i<N; i++) {
    cin >> data.at(i);
  }
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (data.at(i).at(j) == '#') {
        if (check(data, N, i, j)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}

// 解説にも記載のある実装時の注意のパターンを回避できていないため、WAとなるケースがあった。