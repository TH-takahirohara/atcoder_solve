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
  ll N,W;
  cin >> N >> W;
  
  vector<P> vec(N);
  rep(i,0,N) {
    ll a,b;
    cin >> a >> b;
    vec.at(i) = make_pair(a,b);
  }
  
  sort(vec.begin(), vec.end(), greater<P>());
  
  ll ans = 0;
  rep(i,0,N) {
    ll a = vec.at(i).first;
    ll b = vec.at(i).second;
    if (W > b) {
      ans += a * b;
      W -= b;
    } else {
      ans += a * W;
      break;
    }
  }
  cout << ans << endl;
}

