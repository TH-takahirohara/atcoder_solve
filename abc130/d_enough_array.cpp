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
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> rui(N+1);
  rep(i,0,N) rui.at(i+1) = rui.at(i) + A.at(i);

  ll ans = 0;
  rep(i,0,N) {
    ll tmp = N + 1 - (lower_bound(rui.begin(), rui.end(), rui.at(i)+K) - rui.begin());
    ans += tmp;
  }
  cout << ans << endl;
}
