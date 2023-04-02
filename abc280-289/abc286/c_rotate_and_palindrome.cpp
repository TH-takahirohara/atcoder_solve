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
  int N;
  ll A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;

  ll ans = 8e18;
  rep(ite,0,N) {
    ll tmp = 0;
    tmp += A * ite;
    string s1 = "";
    string s2 = "";
    rep(i,0,ite) {
      s1 += S.at(i);
    }
    rep(i,ite,N) {
      s2 += S.at(i);
    }
    string ns = s2 + s1;

    rep(i,0,N/2) {
      if (ns.at(i) != ns.at(N-i-1)) {
        tmp += B;
      }
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
