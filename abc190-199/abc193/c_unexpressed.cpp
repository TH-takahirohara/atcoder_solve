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
  ll ans = N;
  set<ll> st;
  rep(a,2,100005) {
    rep(b,2,35) {
      ll tg = 1; 
      rep(k,0,b) tg *= (ll)a;
      if (tg <= N && !st.count(tg)) {
        ans--;
        st.insert(tg);
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
