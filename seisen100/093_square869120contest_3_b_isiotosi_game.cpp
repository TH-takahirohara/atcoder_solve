#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,W,K;
  cin >> N >> W >> K;

  vector<vector<int> > S(N, vector<int>(W,0));
  vector<vector<int>> def_S(N, vector<int>(W,0));
  
  vector<string> tmp_vec(N);
  
  rep(i,0,N) {
    cin >> tmp_vec.at(i);
  }
  
  // 配列Sに初期化
  rep(i,0,N) {
    rep(j,0,W) {
      S.at(N-i-1).at(j) = tmp_vec.at(i).at(j) - '0';
    }
  }
  def_S = S;
  
  int ans = 0;
  rep(i,0,N) {
    rep(j,0,W) {
      S = def_S;
      // 石があるかどうかの判定用配列
      vector<vector<bool> > han(N, vector<bool>(W,true));
      int tmp_score = 0;
      int iter = 0;
      while (true) {
        // 最初は、押す石が無くなったとする
        if (iter == 0) han.at(i).at(j) = false;
        
        // 石をずらす処理
        vector<vector<int> > NS(N, vector<int>(W,-1));
        rep(i,0,N) {
          rep(j,0,W) {
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
                        
        // 判定用配列の初期化
        han.assign(N, vector<bool>(W,true));
        
        // K個以上連続している値がある場合、判定用配列の当該箇所をfalseにする処理
        bool has_k_ren = false;
        rep(i,0,N) {
          int ind_begin = 0;
          int ind_end = 0;
          int cur_num = S.at(i).at(0);
          rep(j,1,W) {
            if (S.at(i).at(j) == cur_num) {
              ind_end = j;
            } else {
              if (ind_end - ind_begin >= K-1 && cur_num != -1) {
                // すでにK個以上連続していたら,更新処理
                has_k_ren = true;
                rep(ind,ind_begin,ind_end+1) han.at(i).at(ind) = false;
                tmp_score += (ind_end - ind_begin + 1) * cur_num * (int)pow(2, iter);
              }
              ind_begin = j;
              ind_end = j;
              cur_num = S.at(i).at(j);
            }
          }
          
          if (ind_end - ind_begin >= K-1 && cur_num != -1) {
            // K個以上連続していたら,更新処理
            has_k_ren = true;
            rep(ind,ind_begin,ind_end+1) han.at(i).at(ind) = false;
            tmp_score += (ind_end - ind_begin + 1) * cur_num * (int)pow(2, iter);
          }
        }
        
        // K個以上連続する箇所がない場合は、whileループを抜ける。
        if (!has_k_ren) break;
        
        iter++;
      }
      
      ans = max(ans, tmp_score);
    }
  }
  
  cout << ans << endl;
}
