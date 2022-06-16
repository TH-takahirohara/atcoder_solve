// 086 bitごとに独立に考える bit全探索の復習
// 解説を見た後１時間ほど実装を試みたが、結局解けず。
// コードの方向性はそれほど問題ないはずだが、諦めてコードを置く。
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
  
  ll ans = 1;
  rep(ite,0,60) {
    ll tmp = 0;
    for (ll i=0; i < (1<<N); i++) {
      bool can = true;
      rep(j,0,Q) {
        if (!((cal(i, X.at(j)) || cal(i, Y.at(j)) || cal(i, Z.at(j)) == cal(W.at(j), ite)))) can = false;
      }
      
      if (can) tmp++;
    }
    ans *= tmp % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

