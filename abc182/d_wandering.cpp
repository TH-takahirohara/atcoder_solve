// 紙に書いてシミュレーションしてみることで、何を求めれば良いかを検討した。
// 各動作において進む最大値をそれぞれ求め、それとは別に累積和も求めておく。
// 各動作において、現在の座標に先ほど計算した最大値を足した値がその動作における座標の最大値になる。
// 座標の最大値の更新処理を行った後、実際に動作により到達する次の座標を累積和で求めておいた値を足すことで更新していく。
#include <bits/stdc++.h>
#include <atcoder/segtree>
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
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  vector<ll> max_go(N);
  ll tmp_max = -1e9;
  ll now = 0;
  rep(i,0,N) {
    now += A.at(i);
    tmp_max = max(tmp_max, now);
    max_go.at(i) = tmp_max;
  }
  
  vector<ll> rui(N);
  rui.at(0) = A.at(0);
  rep(i,0,N-1) rui.at(i+1) = A.at(i+1) + rui.at(i);
  
  ll ans = 0LL;
  ll now2 = 0LL;
  rep(i,0,N) {
    ans = max(ans, now2 + max_go.at(i));
    now2 += rui.at(i);
  }
  cout << ans << endl;
}

