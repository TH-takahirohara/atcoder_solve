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
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  map<ll,ll> mp;
  rep(i,0,N) {
    mp[A.at(i)]++;
  }

  ll ans = 0;
  for (auto kv : mp) {
    auto key = kv.first;
    auto val = kv.second;
    if (val <= 1) continue;
    ans += val*(val-1)/2;
  }

  rep(i,0,N) {
    cout << ans - (mp.at(A.at(i)) - 1) << endl;
  }
}
