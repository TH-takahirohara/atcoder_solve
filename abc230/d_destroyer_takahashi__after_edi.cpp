// 解説後AC。区間スケジューリング問題と同じアルゴリズムで解ける。
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef pair<ll,ll> P;

int main() {
  ll N,D;
  cin >> N >> D;
  vector<P> vec;
  rep(i,0,N) {
    ll l,r;
    cin >> l >> r;
    vec.emplace_back(l,r);
  }
  sort(vec.begin(), vec.end(), [](P &l, P &r) { return l.second < r.second; });

  ll ans = 1;
  ll start = vec.at(0).second;
  rep(i,1,vec.size()) {
    auto np = vec.at(i);
    if (start + D - 1 < np.first) {
      ans++;
      start = np.second;
    }
  }
  cout << ans << endl;
}
