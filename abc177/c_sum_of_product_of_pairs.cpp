#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 1000000007LL;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  // 累積和を求める
  vector<ll> rui(N+1);
  rep(i,0,N) rui.at(i+1) = rui.at(i) + A.at(i);
  rep(i,0,N+1) rui.at(i) %= MOD;

  ll ans = 0LL;
  rep(i,0,N-1) {
    ans += A.at(i) * (((rui.at(N) - rui.at(i+1)) + MOD) % MOD);
    ans %= MOD;
  }

  cout << ans << endl;
}
