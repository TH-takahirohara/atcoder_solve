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
  ll a,b;
  cin >> a >> b;
  ll A = a, B = b;

  vector<ll> soa;
  for (ll i=2; i*i <= a; i++) {
    if (A % i != 0) continue;
    soa.push_back(i);
    while (A % i == 0) {
      A /= i;
    }
  }
  if (A != 1) soa.push_back(A);

  set<ll> stb;
  for (ll i=2; i*i <= b; i++) {
    if (B % i != 0) continue;
    stb.insert(i);
    while (B % i == 0) {
      B /= i;
    }
  }
  if (B != 1) stb.insert(B);

  ll ans = 0;
  rep(i,0,soa.size()) {
    ll v = soa.at(i);
    if (stb.count(v)) {
      ans++;
    }
  }
  cout << ans + 1 << endl;
}
