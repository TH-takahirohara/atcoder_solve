// 累積和をとって引いている箇所(48行目)は、負の値になる可能性があるのでケアする必要がある。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a*a%mod;
    n = n >> 1;
  }
  return res;
}

int main() {
  ll N,Q;
  cin >> N >> Q;
  
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  vector<ll> C(Q);
  rep(i,0,Q) {
    ll tmp;
    cin >> tmp;tmp--;
    C.at(i) = tmp;
  }
  
  vector<ll> root(N,0);
  rep(i,1,N) {
    root.at(i) = modpow(A.at(i-1), A.at(i), 1000000007);
  }
  
  rep(i,0,N-1) {
    root.at(i+1) += root.at(i);
    root.at(i+1) %= 1000000007;
  }
  
  ll ans = 0LL;
  rep(i,0,Q-1) {
    ll nowi, nxi;
    nowi = C.at(i);
    nxi = C.at(i+1);
    if (nowi > nxi) swap(nowi, nxi);
    ll tmp = root.at(nxi) - root.at(nowi);
    if (tmp < 0) {
      while (tmp < 0) {
        tmp += 1000000007;
      }
    }
    ans += tmp;
    ans %= 1000000007;
  }
  
  ans += root.at(C.at(0)) - root.at(0);
  ans %= 1000000007;
  ans += root.at(C.at(Q-1)) - root.at(0);
  ans %= 1000000007;
  cout << ans << endl;
}
