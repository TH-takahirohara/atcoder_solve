#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 998244353LL;

int main() {
  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;

  ll a2 = (a % MOD);
  ll b2 = (b % MOD);
  ll c2 = (c % MOD);
  ll d2 = (d % MOD);
  ll e2 = (e % MOD);
  ll f2 = (f % MOD);

  ll fir = a2 * b2 % MOD;
  fir = fir * c2 % MOD;
  ll sec = d2 * e2 % MOD;
  sec = sec * f2 % MOD;
  ll ans = ((fir - sec) + MOD) % MOD;

  cout << ans << endl;
}
