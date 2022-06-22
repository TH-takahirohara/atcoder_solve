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
  ll N,K;
  cin >> N >> K;
  
  vector<ll> vec{1};
  rep(i,0,N) {
    ll L;
    cin >> L;
    vector<ll> vecl(L);
    rep(j,0,L) cin >> vecl.at(j);
    
    ll num = vec.size() * L;
    vector<ll> newvec(num);
    rep(j,0,vec.size()) {
      rep(k,0,vecl.size()) {
        double seki = (double)vec.at(j) * vecl.at(k);
        if (seki <= 1e18) newvec.at(j*L + k) = vec.at(j) * vecl.at(k);
        else newvec.at(j*L + k) = 0;
      }
    }
    
    vec = newvec;
  }
  
  ll ans = 0LL;
  rep(i,0,vec.size()) {
    if (vec.at(i) == K) ans++;
  }
  cout << ans << endl;
}

