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
  ll N,M,X;
  cin >> N >> M >> X;
  vector<ll> C(N);
  vector<vector<ll>> vec(N, vector<ll>(M));
  rep(i,0,N) {
    ll c; cin >> c;
    C.at(i) = c;
    rep(j,0,M) cin >> vec.at(i).at(j);
  }

  ll ans = 1e15;
  for (int bit=0; bit<(1<<N); bit++) {
    ll nedan = 0;
    vector<ll> A(M);
    rep(i,0,N) {
      if (bit & (1<<i)) {
        nedan += C.at(i);
        rep(j,0,M) {
          A.at(j) += vec.at(i).at(j);
        }
      }
    }
    bool can = true;
    rep(i,0,M) if (A.at(i) < X) can = false;
    if (can) ans = min(ans, nedan);
  }
  if (ans < 500000000000000) cout << ans << endl;
  else cout << -1 << endl;
}
