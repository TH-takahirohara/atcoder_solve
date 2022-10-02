#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 1000000007LL;
ll N,K;

// k個足した総和は、 0+1+...+k-1 から (N-k+1)+...+(N-1)+N までの全ての値を取りうるはずなので、
// その総数を求める
ll cnt(ll k) {
  return ((2*N-k+1)*k/2 - k*(k-1)/2 + 1) % MOD;
}

int main() {
  cin >> N >> K;

  ll ans = 0;
  // k個の数をたした総和は、その個数以外の個数の総和と同じ値を取ることはない。
  // （各数は、10^100と非常に大きい値に、10^5オーダーという比較すると小さい数を足しているため）
  // そのため、選択する数の個数ごとに排他的に計算して良い。
  rep(i,K,N+2) {
    ans += cnt(i);
    ans %= MOD;
  }
  cout << ans << endl;
}
