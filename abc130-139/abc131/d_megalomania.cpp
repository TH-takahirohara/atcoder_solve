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
  int N; cin >> N;
  vector<pair<ll,ll>> vec(N);
  rep(i,0,N) {
    ll a,b;
    cin >> a >> b;
    vec.at(i) = make_pair(b,a);
  }

  sort(vec.begin(), vec.end());

  string ans = "Yes";
  ll crt = 0;
  rep(i,0,N) {
    crt += vec.at(i).second;
    if (crt > vec.at(i).first) ans = "No";
  }
  cout << ans << endl;
}
