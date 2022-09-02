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
  ll N,L,R;
  cin >> N >> L >> R;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> mina(N+1);
  rep(i,1,N+1) {
    mina.at(i) = min(mina.at(i-1) + A.at(i-1), L*i);
  }

  ll ans = 8e18;
  rep(i,0,N+1) {
    ll tmp = 0;
    tmp = mina.at(i) + R * (N-i);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
