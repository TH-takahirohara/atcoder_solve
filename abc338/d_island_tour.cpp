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
  int N, M;
  cin >> N >> M;
  vector<ll> X(M);
  rep(i,0,M) cin >> X.at(i);

  vector<ll> vec(1e7);
  ll ans = 0;
  rep(i,0,M-1) {
    ll prev = X.at(i);
    ll next = X.at(i+1);
    if (next < prev) swap(prev, next); // nextの方が大きい
    ans += min(next - prev, N - (next - prev)); // ansに加算する
    if ((next - prev) <  (N - (next - prev))) { // 単純な距離の方が短い場合
      ll kasan = (N - (next - prev)) - (next - prev);
      vec.at(prev) += kasan;
      vec.at(next) -= kasan;
    } else if ((next - prev) > (N - (next - prev))) { // ぐるっと回る方が短い場合
      ll kasan = (next - prev) - (N - (next - prev));
      vec.at(next) += kasan;
      vec.at(next+(N - (next - prev))) -= kasan;
    }
  }

  rep(i,0,2e6) {
    vec.at(i+1) += vec.at(i);
  }

  ll minv = 8e18;
  for (int i=0; i <= N-1; i++) {
    minv = min(minv, vec.at(i) + vec.at(i+N));
  }
  cout << ans + minv << endl;
}
