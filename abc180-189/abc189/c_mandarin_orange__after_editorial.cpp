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
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  ll ans = 0;
  for (int l=0; l<N; l++) {
    ll x = A.at(l);
    for (int r=l; r<N; r++) {
      x = min(x, A.at(r));
      ans = max(ans, (r-l+1)*x);
    }
  }
  cout << ans << endl;
}


