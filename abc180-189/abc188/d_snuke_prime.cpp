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
  ll N, C;
  cin >> N >> C;

  vector<vector<ll>> vec;
  rep(i,0,N) {
    ll a,b,c;
    cin >> a >> b >> c;
    b++;
    vec.push_back({a,c,1});
    vec.push_back({b,c,-1});
  }
  sort(vec.begin(), vec.end());

  ll ans = 0;
  ll cur = -1;
  ll sum = 0;
  rep(i,0,vec.size()) {
    auto p = vec.at(i);
    ll day = p.at(0);
    ll co = p.at(1);
    ll sign = p.at(2);
    if (cur == -1) {
      cur = day;
      sum += co;
    } else {
      ans += (day - cur) * min(C, sum);
      sum += co * sign;
      cur = day;
    }
  }
  cout << ans << endl;
}
