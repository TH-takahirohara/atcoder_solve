#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int M, N;
  cin >> M;

  vector<int> tar_x(M), tar_y(M);
  for (int i=0; i<M; i++) {
    cin >> tar_x.at(i) >> tar_y.at(i);
  }
  
  // 0要素からの差分を配列に格納
  vector<int> diff_x(M-1), diff_y(M-1);
  for (int i=1; i<M; i++) {
    diff_x.at(i-1) = tar_x.at(i) - tar_x.at(0);
    diff_y.at(i-1) = tar_y.at(i) - tar_y.at(0);
    
    //cout << diff_x.at(i-1) << " " << diff_y.at(i-1) << endl;
  }
  
  cin >> N;
  vector<pair<int, int>> photo(N, make_pair(-1, -1));
  for (int i=0; i<N; i++) {
    int tmpx, tmpy;
    cin >> tmpx >> tmpy;
    photo.at(i) = make_pair(tmpx, tmpy);
  }
  
  int dx = 0, dy = 0;
  // 写真のそれぞれの星に対して、差分の分ずらしたところに星があるかどうか判定する
  for (int i=0; i<N; i++) {
    int x = photo.at(i).first;
    int y = photo.at(i).second;
    
    bool flag = true;
    // 差分の配列で走査する
    for (int j=0; j<M-1; j++) {
      bool ok_flag = false;
      // 写真の中に、ずらした位置の座標があるかどうか判定
      for (int k=0; k<N; k++) {
        pair<int, int> ptest = make_pair(x + diff_x.at(j), y + diff_y.at(j));
        if (photo.at(k) == ptest) ok_flag = true;
      }
      
      if (!ok_flag) flag = false;
    }
    
    if (flag) {
      dx = x - tar_x.at(0);
      dy = y - tar_y.at(0);
    }
  }
  
  cout << dx << " " << dy << endl;
}
