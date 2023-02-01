#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 1000000007;

int main() {
  ll N; cin >> N;
  vector<ll> C(N);
  rep(i,0,N) cin >> C.at(i);
  sort(C.begin(), C.end());

  ll ans = 1LL;
  rep(i,0,N) {
    ans *= max(C.at(i)-(ll)i, 0LL);
    ans %= MOD;
  }
  cout << ans << endl;
}
