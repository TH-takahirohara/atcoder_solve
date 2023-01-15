#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S;
  cin >> S;

  vector<ll> kake(13);
  kake.at(0) = 1;
  rep(i,0,12) {
    kake.at(i+1) = kake.at(i) * 26;
  }

  int keta_mi1 = S.size();
  ll ans = 0;
  rep(i,0,keta_mi1) {
    ans += kake.at(i);
  }

  rep(i,0,S.size()) {
    ll num = (ll)(S.at(i) - 'A');
    ans += num * kake.at(S.size() - 1 - i);
  }

  cout << ans << endl;
}
