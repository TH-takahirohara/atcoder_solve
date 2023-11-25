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
  ll D;
  cin >> D;

  ll ans = 1e18;
  for (ll i=0; i < 2e6; i++) {
    ll x2 = i * i;
    ll flo = floor(sqrt(D - x2));
    ans = min(ans, abs(x2 + flo * flo - D));
    ll minflo = flo - 1;
    ans = min(ans, abs(x2 + minflo * minflo - D));
    ll maxflo = flo + 1;
    ans = min(ans, abs(x2 + maxflo * maxflo - D));
  }
  cout << ans << endl;
}
