// 考え方は合っていたが、kの値の決め方が不適切で解けなかった。
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
  ll N;
  cin >> N;

  ll k;
  for (ll i=1; i<=N; i++) {
    if (i*i > N) break;
    k = i;
  }

  ll ans = 0;

  for (ll i=1; i<=k; i++) {
    ans += i * (N / i - N / (i + 1));
  }

  for (ll i=1; i<=N/(k+1); i++) {
    ans += N / i;
  }

  cout << ans << endl;
}
