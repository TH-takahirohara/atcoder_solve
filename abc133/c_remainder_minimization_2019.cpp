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
  ll L,R;
  cin >> L >> R;

  if (R - L >= 2018) {
    cout << 0 << endl;
  } else {
    ll ans = 2020LL;
    for (ll i=L; i<R; i++) {
      for (ll j=i+1; j<R+1; j++) {
        ans = min(ans, (i*j) % 2019);
      }
    }
    cout << ans << endl;
  }
}
