#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<char> color = {'R', 'B', 'W'};

int main() {
  int N;
  cin >> N;
  
  vector<string> S(5);
  rep(i,0,5) cin >> S.at(i);
  
  vector<vector<int>> dp(3, vector<int>(N,0));
  int cnt0_r=0, cnt0_b=0, cnt0_w=0;
  rep(i,0,5) {
    if (S.at(i).at(0) == 'R') cnt0_r++;
    if (S.at(i).at(0) == 'B') cnt0_b++;
    if (S.at(i).at(0) == 'W') cnt0_w++;
  }
  dp.at(0).at(0) = 5-cnt0_r;
  dp.at(1).at(0) = 5-cnt0_b;
  dp.at(2).at(0) = 5-cnt0_w;

  rep(i,1,N) {
    int cnt_r=0, cnt_b=0, cnt_w=0;
    rep(j,0,5) {
      if (S.at(j).at(i) == 'R') cnt_r++;
      if (S.at(j).at(i) == 'B') cnt_b++;
      if (S.at(j).at(i) == 'W') cnt_w++;
    }
    dp.at(0).at(i) = 5 - cnt_r + min(dp.at(1).at(i-1), dp.at(2).at(i-1));
    dp.at(1).at(i) = 5 - cnt_b + min(dp.at(0).at(i-1), dp.at(2).at(i-1));
    dp.at(2).at(i) = 5 - cnt_w + min(dp.at(0).at(i-1), dp.at(1).at(i-1));
  }

  int ans = 0;
  rep(i,0,3) ans = max(ans, dp.at(i).at(N-1));
  cout << ans << endl;
}
