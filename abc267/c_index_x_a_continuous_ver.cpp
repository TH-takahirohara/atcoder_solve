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
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> rui(N+1);
  rep(i,0,N) rui.at(i+1) = rui.at(i) + A.at(i);
  // rep(i,0,N+1) cout << rui.at(i) << " ";

  ll ans = 0;
  rep(i,0,M) {
    ans += A.at(i) * (i+1);
  }
  ll bef = ans;
  rep(i,1,N-M+1) {
    // cout << i << endl;
    ll tmp = bef - (rui.at(i+M-1) - rui.at(i-1)) + A.at(i+M-1) * M;
    // cout << i << " " << ans <<  " " << rui.at(i+M-1) - rui.at(i-1) << " " <<  tmp << endl;
    bef = tmp;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
