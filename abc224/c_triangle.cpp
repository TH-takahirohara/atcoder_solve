#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  vector<ll> X(N), Y(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i);
  
  ll ans = 0LL;
  rep(i,0,N) {
    rep(j,i+1,N) {
      rep(k,j+1,N) {
        ll x1 = X.at(i); ll y1 = Y.at(i);
        ll x2 = X.at(j); ll y2 = Y.at(j);
        ll x3 = X.at(k); ll y3 = Y.at(k);
        
        if (x1 == x2 && x2 == x3) continue;
        if (y1 == y2 && y2 == y3) continue;
        if (y3*(x2-x1) == (y2-y1)*(x3-x1)+y1*(x2-x1)) continue;
        ans++;
      }
    }
  }
  cout << ans << endl;
}

