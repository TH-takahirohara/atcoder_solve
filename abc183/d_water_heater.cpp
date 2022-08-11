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
  ll N,W;
  cin >> N >> W;
  vector<ll> S(N), T(N), P(N);
  rep(i,0,N) cin >> S.at(i) >> T.at(i) >> P.at(i);

  vector<ll> vec(2000100, 0);
  rep(i,0,N) {
    vec.at(S.at(i)) += P.at(i);
    vec.at(T.at(i)) -= P.at(i);
  }

  rep(i,0,200050) {
    vec.at(i+1) += vec.at(i);
  }

  string ans = "Yes";
  rep(i,0,200001) {
    if (vec.at(i) > W) ans = "No";
  }
  cout << ans << endl;
}
