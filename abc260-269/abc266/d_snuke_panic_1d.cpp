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
  ll N;
  cin >> N;
  vector<ll> T(N), X(N), A(N);
  rep(i,0,N) cin >> T.at(i) >> X.at(i) >> A.at(i);

  vector<vector<ll>> dp(5, vector<ll>(N, 0));
  if (T.at(0) >= X.at(0)) dp.at(X.at(0)).at(0) = A.at(0);

  rep(ite,1,N) {
    ll tim = T.at(ite) - T.at(ite-1);
      rep(now,0,5) {
        if (T.at(ite) < now) continue;
        rep(bef,0,5) {
          if (abs(now - bef) <= tim) dp.at(now).at(ite) = max(dp.at(now).at(ite), dp.at(bef).at(ite-1));
        }
        if (now == X.at(ite)) dp.at(now).at(ite) += A.at(ite);
      }
  }

  ll ans = 0;
  rep(i,0,5) {
    ans = max(ans, dp.at(i).at(N-1));
  }
  cout << ans << endl;
}
