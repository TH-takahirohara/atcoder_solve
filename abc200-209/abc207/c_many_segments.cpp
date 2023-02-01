#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef pair<double,double> P;

int main() {
  ll N;
  cin >> N;
  vector<P> vec(N);
  rep(i,0,N) {
    int t;
    double l,r;
    cin >> t >> l >> r;

    if (t==2) {
      r -= 0.2;
    } else if (t==3) {
      l += 0.2;
    } else if (t==4) {
      l += 0.2;
      r -= 0.2;
    }
    vec.at(i) = make_pair(l,r);
  }

  ll ans = 0;
  rep(i,0,N) {
    rep(j,i+1,N) {
      P p1 = vec.at(i);
      P p2 = vec.at(j);
      if (p1.second < p2.first || p2.second < p1.first) continue;
      ans++;
    }
  }
  cout << ans << endl;
}
