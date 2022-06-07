// 081 データを二次元にプロット／二次元累積和
// 分からず、解説後AC
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int N,K;
  cin >> N >> K;
  
  vector<vector<ll>> A(5000, vector<ll>(5000, 0));
  rep(i,0,N) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    A.at(a).at(b) += 1;
  }
  
  vector<vector<ll>> S(5001, vector<ll>(5001,0));
  rep(i,0,5000) {
    rep(j,0,5000) {
      S.at(i+1).at(j+1) = S.at(i).at(j+1) + S.at(i+1).at(j) - S.at(i).at(j) + A.at(i).at(j);
    }
  }
  
  ll ans = 0;
  rep(i,0,5000-K) {
    rep(j,0,5000-K) {
      ll tmp = S.at(i+K+1).at(j+K+1) - S.at(i+K+1).at(j) - S.at(i).at(j+K+1) + S.at(i).at(j);
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}

