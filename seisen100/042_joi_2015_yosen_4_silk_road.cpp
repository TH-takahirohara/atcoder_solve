#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 1000010000;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> D(N), C(M);
  rep(i,0,N) cin >> D.at(i);
  rep(i,0,M) cin >> C.at(i);
  
  vector<vector<int>> dp(M+1, vector<int>(N+1, INF));
  dp.at(0).assign(N+1, 0);
  dp.at(1).at(0) = 0;
  dp.at(1).at(1) = D.at(0) * C.at(0);
  rep(i,2,M+1) {
    rep(j,0,N+1) {
      dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j));
      if (j-1>=0) dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j-1) + D.at(j-1) * C.at(i-1));
    }
  }
  
  cout << dp.at(M).at(N) << endl;
}
