#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

// N: 金額、M: コインの種類数
int N, M;

int main() {
  cin >> N >> M;
  
  vector<int> C(M+1);
  rep(i,0,M) cin >> C.at(i);
  
  vector<vector<int> > dp(M+1, vector<int>(N+1, 0));
  rep(j,0,N+1) dp.at(0).at(j) = j;
  
  rep(i,1,M) {
    rep(j,0,N+1) {
      if (j-C.at(i) >= 0) {
        dp.at(i).at(j) = min(dp.at(i-1).at(j-C.at(i)) + 1, dp.at(i).at(j-C.at(i)) + 1);
        dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j));
      } else {
        dp.at(i).at(j) = dp.at(i-1).at(j);
      }
    }
  }
  
  cout << dp.at(M-1).at(N) << endl;
}
