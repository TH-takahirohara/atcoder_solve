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
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<ll> R(N), G(N), B(N);
  rep(i,0,N) {
    if (S.at(i) == 'R') R.at(i) = 1;
    else if (S.at(i) == 'G') G.at(i) = 1;
    else B.at(i) = 1;
  }
  vector<ll> ruir(N+1), ruig(N+1), ruib(N+1);
  rep(i,0,N) {
    ruir.at(i+1) = R.at(i) + ruir.at(i);
    ruig.at(i+1) = G.at(i) + ruig.at(i);
    ruib.at(i+1) = B.at(i) + ruib.at(i);
  }

  ll ans = 0;
  rep(ite,0,N-2) {
    rep(j,ite+1,N-1) {
      if (S.at(ite) == S.at(j)) continue;
      if ((S.at(ite) == 'R' && S.at(j) == 'G') || (S.at(ite) == 'G' && S.at(j) == 'R')) {
        if (j+(j-ite) > N-1) ans += ruib.at(N) - ruib.at(j+1);
        else ans += ruib.at(j+(j-ite)) - ruib.at(j+1) + ruib.at(N) - ruib.at(j+(j-ite)+1);
      }
      if ((S.at(ite) == 'R' && S.at(j) == 'B') || (S.at(ite) == 'B' && S.at(j) == 'R')) {
        if (j+(j-ite) > N-1) ans += ruig.at(N) - ruig.at(j+1);
        else ans += ruig.at(j+(j-ite)) - ruig.at(j+1) + ruig.at(N) - ruig.at(j+(j-ite)+1);
      }
      if ((S.at(ite) == 'G' && S.at(j) == 'B') || (S.at(ite) == 'B' && S.at(j) == 'G')) {
        if (j+(j-ite) > N-1) ans += ruir.at(N) - ruir.at(j+1); 
        else ans += ruir.at(j+(j-ite)) - ruir.at(j+1) + ruir.at(N) - ruir.at(j+(j-ite)+1);
      }
    }
  }
  cout << ans << endl;
}
