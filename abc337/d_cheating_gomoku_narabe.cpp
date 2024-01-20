#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);

  vector<vector<int>> rui_yoko(R, vector<int>(C+1));
  vector<vector<int>> rui_tate(C, vector<int>(R+1));
  rep(i,0,R) {
    rep(j,0,C) {
      int tasu = 0;
      if (S.at(i).at(j) == 'o') tasu++;
      rui_yoko.at(i).at(j+1) = rui_yoko.at(i).at(j) + tasu;
    }
  }

  rep(j,0,C) {
    rep(i,0,R) {
      int tasu = 0;
      if (S.at(i).at(j) == 'o') tasu++;
      rui_tate.at(j).at(i+1) = rui_tate.at(j).at(i) + tasu;
    }
  }

  vector<vector<int>> batu_yoko(R);
  vector<vector<int>> batu_tate(C);

  rep(i,0,R) {
    rep(j,0,C) {
      if (S.at(i).at(j) == 'x') {
        batu_yoko.at(i).push_back(j);
      }
    }
    batu_yoko.at(i).push_back(C);
  }

  rep(j,0,C) {
    rep(i,0,R) {
      if (S.at(i).at(j) == 'x') {
        batu_tate.at(j).push_back(i);
      }
    }
    batu_tate.at(j).push_back(R);
  }

  int ans = 1e9;
  rep(i,0,R) {
    rep(j,0,C) {
      int tmp = 1e9;
      if (S.at(i).at(j) == 'x') continue;
      // 横方向
      auto b_yoko = batu_yoko.at(i);
      auto nx_batu_idx = *lower_bound(b_yoko.begin(), b_yoko.end(), j);
      if (nx_batu_idx - j >= K) {
        int k_idx = j + K -1;
        // rep(k,0,C+1) {
        //   cout << rui_yoko.at(i).at(k) << " ";
        // }
        // cout << endl;
        int maru = rui_yoko.at(i).at(k_idx+1) - rui_yoko.at(i).at(j+1);
        // cout << "j rui: " << rui_yoko.at(i).at(j) << endl;
        // cout << "k_idx rui: " << rui_yoko.at(i).at(k_idx) << endl;
        // cout << "maru: " << maru << endl;
        // int tasu = 0;
        if (S.at(i).at(j) == 'o') maru++;
        tmp = min(tmp, K - maru);
      }

      // 縦方向
      auto b_tate = batu_tate.at(j);
      auto nx_tate_batu_idx = *lower_bound(b_tate.begin(), b_tate.end(), i);
      if (nx_tate_batu_idx - i >= K) {
        int k_idx = i + K - 1;
        int maru = rui_tate.at(j).at(k_idx+1) - rui_tate.at(j).at(i+1);
        // int tasu = 0;
        if (S.at(i).at(j) == 'o') maru++;
        tmp = min(tmp, K - maru);
      }

      ans = min(ans, tmp);
    }
  }

  if (ans >= 5e8) cout << -1 << endl;
  else cout << ans << endl;
}
