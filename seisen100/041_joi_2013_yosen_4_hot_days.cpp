// 入力例1の場合
// can_map（各日付において着ることができる服を判定する行列）
//    30 90 60 40
// 1d F  F  T  T
// 2d F  T  T  F
// 3d F  F  T  F
//
// dp（ある日においてcan_mapの服がtrueの場合、その前日においてcan_mapがtrueの服の派手さとの差分を、その前日のdpの値に加算し、maxをとる）
// 例えば、下図の3d,60のところについては、50+abs(90-60)=80 と 20+abs(60-60)=20 を比較し、より大きい80を取っている。
//    30 90 60 40
// 1d 0  0  0  0
// 2d 0  50 20 0
// 3d 0  0  80 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int D,N;
  cin >> D >> N;
  
  vector<int> T(D);
  rep(i,0,D) cin >> T.at(i);
  
  vector<int> A(N), B(N), C(N);
  rep(i,0,N) cin >> A.at(i) >> B.at(i) >> C.at(i);
  
  vector<vector<bool>> can_map(D, vector<bool>(N, false));
  rep(i,0,D) {
    rep(j,0,N) {
      if (A.at(j) <= T.at(i) && T.at(i) <= B.at(j)) can_map.at(i).at(j) = true;
    }
  }
  
  vector<vector<int>> dp(D, vector<int>(N, 0));
  rep(i,1,D) {
    rep(j,0,N) {
      if (!can_map.at(i).at(j)) continue;
      rep(k,0,N) {
        if (can_map.at(i-1).at(k)) {
          dp.at(i).at(j) = max(dp.at(i).at(j), abs(C.at(j) - C.at(k)) + dp.at(i-1).at(k));
        }
      }
    }
  }

  int ans = 0;
  rep(j,0,N) ans = max(ans, dp.at(D-1).at(j));

  cout << ans << endl;
}
