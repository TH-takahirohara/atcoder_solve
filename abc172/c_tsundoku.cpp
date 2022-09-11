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
  ll N,M,K;
  cin >> N >> M >> K;
  vector<ll> A(N), B(M);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,M) cin >> B.at(i);

  vector<ll> ruia(N+1), ruib(M+1);
  rep(i,0,N) ruia.at(i+1) = ruia.at(i) + A.at(i);
  rep(i,0,M) ruib.at(i+1) = ruib.at(i) + B.at(i);

  ll cnt = upper_bound(ruia.begin(), ruia.end(), K) - ruia.begin() - 1;
  ll ans = 0;
  while (cnt >= 0) {
    ll tmp = cnt;
    ll nokori = K - ruia.at(cnt);
    ll cntb = upper_bound(ruib.begin(), ruib.end(), nokori) - ruib.begin() - 1;
    tmp += cntb;
    ans = max(ans, tmp);
    cnt--;
  }
  cout << ans << endl;
}
