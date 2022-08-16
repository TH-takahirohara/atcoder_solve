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
  ll N,K;
  cin >> N >> K;
  vector<double> P(N);
  rep(i,0,N) {
    ll p; cin >> p;
    P.at(i) = (double)(p+1)*p/(2.0*p);
  }

  double cur = 0.0;
  rep(i,0,K) cur += P.at(i);

  double ans = cur;
  rep(i,0,N-K) {
    cur = cur + P.at(i+K) - P.at(i);
    ans = max(ans, cur);
  }
  cout << fixed << setprecision(10) << ans << endl;
}
