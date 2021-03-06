#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N, W;
  cin >> N >> W;
  
  vector<int> V(N+1);
  vector<int> Ws(N+1);
  rep(i,1,N+1) {
    cin >> V.at(i);
    cin >> Ws.at(i);
  }
  
  vector<vector<int> > dp(N+1, vector<int>(W+1, 0));
  
  rep(i,1,N+1) {
    rep(j,1,W+1) {
      if (j - Ws.at(i) < 0) dp.at(i).at(j) = dp.at(i-1).at(j);
      else dp.at(i).at(j) = max(dp.at(i-1).at(j-Ws.at(i))+V.at(i), dp.at(i-1).at(j));
    }
  }
  
  cout << dp.at(N).at(W) << endl;
}
