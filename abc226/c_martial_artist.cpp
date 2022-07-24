#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<bool> need;
vector<vector<ll>> vec;

void rec(int v) {
  if (need.at(v)) return;
  
  need.at(v) = true;
  for (auto nv : vec.at(v)) {
    if (need.at(nv)) continue;
    rec(nv);
  }
}

int main() {
  int N;
  cin >> N;
  need.assign(N, false);
  vector<ll> T(N);
  vec.assign(N, {});
  
  rep(i,0,N) {
    ll t;
    int k;
    cin >> t >> k;
    T.at(i) = t;
    rep(j,0,k) {
      ll a;
      cin >> a; a--;
      vec.at(i).push_back(a);
    }
  }
  
  rec(N-1);
  
  ll ans = 0LL;
  rep(i,0,N) {
    if (need.at(i)) ans += T.at(i);
  }
  cout << ans << endl;
}

