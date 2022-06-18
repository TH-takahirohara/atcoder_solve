// 086 bitごとに独立に考える bit全探索の復習
// solまでみて、書き換えることでACした。
#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 1000000007LL;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

bool cal(ll val, int idx) {
  return (val & (1<<idx)) > 0;
}

int main() {
  int N,Q;
  cin >> N >> Q;
  
  vector<int> X(Q), Y(Q), Z(Q);
  vector<ll> W(Q);
  rep(i,0,Q) {
    int x,y,z;
    ll w;
    cin >> x >> y >> z >> w;
    x--;y--;z--;
    X.at(i) = x; Y.at(i) = y; Z.at(i) = z; W.at(i) = w;
  }
  
  vector<vector<int>> wbit(Q, vector<int>(60));
  rep(i,0,Q) {
    ll wtmp = W.at(i);
    for (ll j=0; j<60; j++) {
      if (wtmp % 2 != 0) wbit.at(i).at(j) = 1;
      else wbit.at(i).at(j) = 0;
      wtmp /= 2;
    }
  }
  
  ll ans = 1;
  rep(ite,0,60) {
    ll tmp = 0;
    for (ll i=0; i < (1<<N); i++) {
      bool can = true;
      vector<int> bit(N);
      rep(k,0,N) {
        if (i & (1<<k)) bit.at(k) = 1;
        else bit.at(k) = 0;
      }
      
      rep(j,0,Q) {
        if ((bit.at(X.at(j)) | bit.at(Y.at(j)) | bit.at(Z.at(j))) != wbit.at(j).at(ite)) can = false;
      }
      
      if (can) tmp++;
    }
    ans *= tmp % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

