#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int X,Y,A,B,C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> P(A), Q(B), R(C), NP(X), NQ(Y);

  rep(i,0,A) cin >> P.at(i);
  rep(i,0,B) cin >> Q.at(i);
  rep(i,0,C) cin >> R.at(i);

  sort(P.begin(), P.end(), greater<ll>());
  sort(Q.begin(), Q.end(), greater<ll>());
  sort(R.begin(), R.end(), greater<ll>());

  rep(i,0,X) NP.at(i) = P.at(i);
  rep(i,0,Y) NQ.at(i) = Q.at(i);

  // X,Y個まで小さい順
  reverse(NP.begin(), NP.end());
  reverse(NQ.begin(), NQ.end());

  int idx_p = 0, idx_q = 0;
  rep(i,0,C) {
    if (R.at(i) < NP.at(idx_p) && R.at(i) < NQ.at(idx_q)) break;
    if (R.at(i) < NP.at(idx_p)) {
      NQ.at(idx_q) = R.at(i);
      if (idx_q < Y-1) idx_q++;
    } else if (R.at(i) < NQ.at(idx_q)) {
      NP.at(idx_p) = R.at(i);
      if (idx_p < X-1) idx_p++;
    } else {
      if (NP.at(idx_p) < NQ.at(idx_q)) {
        NP.at(idx_p) = R.at(i);
        if (idx_p < X-1) idx_p++;
      } else {
        NQ.at(idx_q) = R.at(i);
        if (idx_q < Y-1) idx_q++;
      }
    }
  }

  ll ans = 0;
  rep(i,0,X) ans += NP.at(i);
  rep(i,0,Y) ans += NQ.at(i);
  cout << ans << endl;
}
