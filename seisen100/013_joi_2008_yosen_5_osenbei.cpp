#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int R, C;
vector<vector<int>> senbei;

int main() {
  cin >> R >> C;
  senbei.assign(R, vector<int>(C));
  
  // 入力
  rep(i, 0, R) {
    rep(j, 0, C) {
      cin >> senbei.at(i).at(j);
    }
  }
  
  int ans = 0;
  rep(i, 0, (1 << R)) {
    int tmp_sum = 0;
    rep(j, 0, C) {
      int col_sum1 = 0;
      rep(k, 0, R) {
        if (!(i & (1 << k)) && senbei.at(k).at(j) == 1) col_sum1++;
        if ((i & (1 << k)) && senbei.at(k).at(j) == 0) col_sum1++;
      }
      tmp_sum += max(col_sum1, R - col_sum1);
    }
    
    ans = max(ans, tmp_sum);
  }
  
  cout << ans << endl;
}
