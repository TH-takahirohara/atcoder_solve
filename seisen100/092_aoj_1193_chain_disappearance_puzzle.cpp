#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  while (true) {
    int N;
    cin >> N;
    if (N==0) break;
    
    vector<vector<int> > S(N, vector<int>(5,0));
    //vector<vector<bool> > han(N, vector<bool>(5,true));
    
    // 石を配列Sに初期化
    rep(i,0,N) {
      rep(j,0,5) {
        cin >> S.at(N-i-1).at(j);
      }
    }
    
    int ans = 0;
    while (true) {
      vector<vector<bool> > han(N, vector<bool>(5,true));
      // 1. 3つ以上連続している値がある場合、判定用配列の当該箇所をfalseにする処理
      bool has_three_ren = false;
      rep(i,0,N) {
        int ind_begin = 0;
        int ind_end = 0;
        int cur_num = S.at(i).at(0);
        rep(j,1,5) {
          if (S.at(i).at(j) == cur_num) {
            ind_end = j;
          } else {
            if (ind_end - ind_begin >= 2) {
              // すでに3つ以上連続していたら抜ける
              break;
            } else {
              // 3つ以上連続していなければ、indexとcur_numを更新して次へ
              ind_begin = j;
              ind_end = j;
              cur_num = S.at(i).at(j);
            }
          }
        }
        
        if (ind_end - ind_begin >= 2 && cur_num != -1) {
          // 3つ以上連続する箇所がある場合、フラグを立てて、判定用配列の当該箇所をfalseで更新数r
          has_three_ren = true;
          rep(ind,ind_begin,ind_end+1) han.at(i).at(ind) = false;
          ans += (ind_end - ind_begin + 1) * cur_num;
        }
      }
      
      // 3つ以上連続する箇所がない場合は、whileループを抜ける。
      if (!has_three_ren) break;
      
      // 2. 石をずらす処理
      vector<vector<int> > NS(N, vector<int>(5,-1));
      rep(i,0,N) {
        rep(j,0,5) {
          // -1(石がない場合)なら飛ばす
          if (S.at(i).at(j) == -1) continue;
          // 削除される石である場合、NS配列を-1に更新して飛ばす
          if (!han.at(i).at(j)) {
            NS.at(i).at(j) = -1;
            continue;
          }
          
          int cnt_down = 0;
          rep(dw,1,N) {
            if ((i - dw) < 0) break;
            if (!han.at(i-dw).at(j)) cnt_down++;
          }

          if (i-cnt_down >= 0) {
            NS.at(i-cnt_down).at(j) = S.at(i).at(j);
          }
        }
      }
      S = NS;
    }
    
    cout << ans << endl;
  }
  return 0;
}
