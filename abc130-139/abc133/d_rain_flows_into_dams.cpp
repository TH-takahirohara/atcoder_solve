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

  ll fir = 0;
  rep(i,0,N) {
    if (i % 2 == 0) fir += A.at(N-i-1);
    else fir -= A.at(N-i-1);
  }

  vector<ll> ans(N);
  ans.at(0) = fir;
  rep(i,1,N) {
    ans.at(i) = (A.at(i-1) - ans.at(i-1)/2) * 2;
  }
  rep(i,0,N) {
    if (i!=N-1) cout << ans.at(i) << " ";
    else cout << ans.at(i) << endl;
  }
}
