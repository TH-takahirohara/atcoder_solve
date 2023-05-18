#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll N, M;
  cin >> N >> M;

  ll ans = 1e18;
  for (ll i=1; i*i <= M*1000; i++) {
    if (i > N) break;
    ll b = M / i;
    if (i * min(b, N) < M && i * min(b+1, N) < M) continue;
    while (true) {
      if (i * min(b, N) >= M) break;
      b++;
    }

    if (i * b == M) {
      cout << M << endl;
      return 0;
    } else if (i * b > M) {
      ans = min(ans, i * b);
    }
  }

  if (ans >= 1e18 / 2) cout << -1 << endl;
  else cout << ans << endl;
}
