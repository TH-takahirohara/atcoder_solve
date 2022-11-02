// 考え方は合っていたが、kの値の決め方が不適切で解けなかった。
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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  map<ll,ll> mp_ipa;
  rep(i,0,N) {
    mp_ipa[i+A.at(i)]++;
  }

  ll ans = 0;
  rep(i,0,N) {
    if (mp_ipa.count(-A.at(i)+i)) ans += mp_ipa.at(-A.at(i)+i);
  }
  cout << ans << endl;
}
