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
  ull N, M;
  cin >> N >> M;

  ull ans = 8e18;
  for (ull i=1; i <= N; i++) {
    if (i > ceil(sqrt(M))) break;
    ull b = (M + i - 1) / i;
    if (b > N) continue;
    ans = min(ans, i * b);
  }

  if (ans >= 8e18 / 2) cout << -1 << endl;
  else cout << ans << endl;
}
