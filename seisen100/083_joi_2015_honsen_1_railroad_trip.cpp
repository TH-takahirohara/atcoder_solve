#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N,M;
  cin >> N >> M;
  
  vector<ll> P(M);
  rep(i,0,M) {
    ll tmp;
    cin >> tmp;
    tmp--;
    P.at(i) = tmp;
  }
  
  vector<ll> A(N-1), B(N-1), C(N-1);
  rep(i,0,N-1) {
    cin >> A.at(i) >> B.at(i) >> C.at(i);
  }
  
  // imos method
  vector<ll> S(N, 0);
  rep(i,0,M-1) {
    ll st=P.at(i);
    ll en=P.at(i+1);
    if (st > en) swap(st, en);
    S.at(st) += 1;
    S.at(en) -= 1;
  }
  
  rep(i,0,N-1) S.at(i+1) += S.at(i);
  
  ll ans = 0LL;
  rep(i,0,N-1) {
    ll cnt = S.at(i);
    ll kippu = A.at(i)*cnt;
    ll ic = B.at(i)*cnt + C.at(i);
    if (ic < kippu) ans += ic;
    else ans += kippu;
  }
  
  cout << ans << endl;
}
