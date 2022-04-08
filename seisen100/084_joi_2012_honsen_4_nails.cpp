#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,M;
  cin >> N >> M;
  
  
  vector<vector<int>> S(5010, vector<int>(5010, 0));
  rep(i,0,M) {
    int a,b,x;
    cin >> a >> b >> x;
    a--;b--;
    
    S.at(a).at(b) += 1;
    S.at(a).at(b+1) -= 1;
    S.at(a+x+1).at(b) -= 1;
    S.at(a+x+2).at(b+1) += 1;
    S.at(a+x+1).at(b+x+2) += 1;
    S.at(a+x+2).at(b+x+2) -= 1;
  }
  
  // 左 -> 右 に累積
  rep(i,0,5001) {
    rep(j,0,5001) {
      S.at(i).at(j+1) += S.at(i).at(j);
    }
  }
  // 上 -> 下 に累積
  rep(j,0,5001) {
    rep(i,0,5001) {
      S.at(i+1).at(j) += S.at(i).at(j);
    }
  }
  // 左上 -> 右下 に累積
  rep(i,0,5001) {
    rep(j,0,5001) {
      if (i+j > 5001) break;
      S.at(i+j+1).at(j+1) += S.at(i+j).at(j);
    }
  }
  
  ll ans = 0LL;
  rep(i,0,5000) {
    rep(j,0,5000) {
      if (S.at(i).at(j) > 0) ans++;
    }
  }
  
  cout << ans << endl;
}

