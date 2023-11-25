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
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  vector<ll> yoko(N), tate(N);
  rep(i,0,N) {
    ll tmp = 0;
    rep(j,0,N) {
      if (S.at(i).at(j) == 'o') tmp++;
    }
    yoko.at(i) = tmp;
  }
  rep(j,0,N) {
    ll tmp = 0;
    rep(i,0,N) {
      if (S.at(i).at(j) == 'o') tmp++;
    }
    tate.at(j) = tmp;
  }

  ll ans = 0;
  rep(i,0,N) {
    rep(j,0,N) {
      if (S.at(i).at(j) != 'o') continue;
      ll yo = yoko.at(i) - 1;
      ll ta = tate.at(j) - 1;
      ans += yo * ta;
    }
  }
  cout << ans << endl;
}
