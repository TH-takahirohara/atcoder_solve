// 解説後AC。調和級数の考え方を使うと、計算量がO(NlogN)に収まるため、解ける。
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
  int N,M;
  cin >> N >> M;
  vector<ll> A(N+1);
  rep(i,1,N+1) cin >> A.at(i);

  vector<set<ll>> sets(M+1);
  rep(i,1,N+1) {
    int st = 1;
    if (A.at(i) < 0) st = -A.at(i) / (i+1);
    rep(j,st,M+1) {
      if (A.at(i) + i*j > N) break;
      sets.at(j).insert(A.at(i) + i*j);
    }
  }

  rep(i,1,M+1) {
    ll ans = 0;
    rep(j,0,N+1) {
      if (sets.at(i).count(j)) continue;
      ans = j;
      break;
    }
    cout << ans << endl;
  }
}
