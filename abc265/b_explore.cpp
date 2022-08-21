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
  ll N,M,T;
  cin >> N >> M >> T;
  vector<ll> A(N-1);
  rep(i,0,N-1) cin >> A.at(i);
  vector<ll> bonus(N);
  rep(i,0,M) {
    ll x,y;
    cin >> x >> y;
    x--;
    bonus.at(x) = y;
  }

  string ans = "Yes";
  rep(i,0,N-1) {
    T -= A.at(i);
    if (T <= 0) {
      ans = "No";
      break;
    }
    if (bonus.at(i+1) > 0) T += bonus.at(i+1);
  }
  cout << ans << endl;
}
