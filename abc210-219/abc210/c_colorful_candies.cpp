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
  vector<ll> C(N);
  rep(i,0,N) cin >> C.at(i);
  
  map<ll,ll> mp;
  ll cnt = 0;
  rep(i,0,K) {
    if (!mp.count(C.at(i))) cnt++;
    mp[C.at(i)]++;
  }
  
  ll ans = 0;
  rep(i,0,N-K) {
    if (mp[C.at(K+i)] == 0) {
      cnt++;
    }
    mp[C.at(K+i)]++;
    
    mp[C.at(i)]--;
    if (mp[C.at(i)] == 0) {
      cnt--;
    }

    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
