#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N;
  cin >> N;
  
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  vector<ll> vec(3,0);
  
  ll ans = 1LL;
  rep(i,0,N) {
    ll nh = A.at(i);
    ll cnt = 0;
    rep(i,0,3) {
      if (nh == vec.at(i)) cnt++;
    }
    
    ans *= cnt;
    ans %= 1000000007;
    
    rep(i,0,3) {
      if (nh == vec.at(i)) {
        vec.at(i) += 1;
        break;
      }
    }
  }
  
  cout << ans << endl;
}
