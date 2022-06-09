// 084(★3) (P1)ランレングス圧縮 (P2)累積的に計算しよう
// 方向性としては後者の方法(P2)で解いた。
// i番目がoだった場合、それより右側で最初にxが出現する箇所を含めて以降をrとすれば、
// l=i とした場合の[l,r]の個数が求まる。（i番目がxだった場合も同様）
// P1は、余事象の考え方も使っていた。
#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  vector<ll> ruix(N), ruio(N);
  rep(i,0,N) {
    if (S.at(i) == 'x') ruix.at(i) += 1;
    else ruio.at(i) += 1;
    if (i != N-1) {
      ruix.at(i+1) = ruix.at(i);
      ruio.at(i+1) = ruio.at(i);
    }
  }
  
  ll ans = 0LL;
  rep(i,0,N) {
    ll tmp = 0LL;
    if (S.at(i) == 'o') {
      tmp = (ll)N - (lower_bound(ruix.begin(), ruix.end(), ruix.at(i) + 1) - ruix.begin());
    } else {
      tmp = (ll)N - (lower_bound(ruio.begin(), ruio.end(), ruio.at(i) + 1) - ruio.begin());
    }
    ans += tmp;
  }
  cout << ans << endl;
}

