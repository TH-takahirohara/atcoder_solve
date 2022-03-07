#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<int>> data(H, vector<int>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  int max_v = 0;
  
  // 行でbit全探索
  for (int bit=0; bit < (1 << H); bit++) {
    // 列方向に重複する値の配列
    vector<int> r;
    // 横方向への走査
    for (int i=0; i<W; i++) {
      // 同じ列の値が同じか否かのflag
      bool flag = true;
      int tmp = -1;
      for (int j=0; j<H; j++) {
        if (bit & (1 << j)) {
          if (tmp == -1) {
            tmp = data.at(j).at(i);
          } else if (tmp != data.at(j).at(i)) {
            flag = false;
            break;
          }
        }
      }
      if (flag && tmp != -1) r.push_back(tmp);
    }
    
    // 重複する配列内で要素数が最も多い値を求める
    map<int, int> M;
    int col_num = 0;
    for (auto v : r) {
      M[v] += 1;
      col_num = max(col_num, M.at(v));
    }
    
    // 行数を求め、col_numにかける
    int row_num = 0;
    for (int j=0; j<H; j++) {
      if (bit & (1 << j)) {
        row_num += 1;
      }
    }
    int ret = col_num * row_num;
    
    max_v = max(max_v, ret);
  }
  
  cout << max_v << endl;
}

