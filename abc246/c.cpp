#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N,K,X;
  cin >> N >> K >> X;
  
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  ll ans = 0LL;
  vector<ll> amaris;
  
  rep(i,0,N) {
    ll mai = A.at(i) / X;
    ll amari = A.at(i) % X;
    amaris.push_back(amari);
    
    if (mai == 0) {
      ans += A.at(i);
    } else if (K == 0) {
      ans += A.at(i);
    } else if (K > mai) {
      K = K - mai;
      ans += (A.at(i) - mai * X);
    } else if (K <= mai) {
      ans += (A.at(i) - K * X);
      K = 0;
    }
  }
  
  sort(amaris.begin(), amaris.end(), greater<ll>());
  if (amaris.size() > 1) {
    rep(i,0,K) {
      if (i > amaris.size()-1) break;
      ans -= amaris.at(i);
    }
  }
  
  if (ans <= 0) cout << 0 << endl;
  else cout << ans << endl;
}
