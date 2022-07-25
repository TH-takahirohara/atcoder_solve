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
  
  vector<ll> X(N), Y(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i);
  
  set<pair<ll,ll>> st;
  
  rep(i,0,N) {
    rep(j,0,N) {
      if (i==j) continue;
      ll x_cur = X.at(i);
      ll y_cur = Y.at(i);
      ll x_tar = X.at(j);
      ll y_tar = Y.at(j);
      
      ll xdiff = x_cur - x_tar;
      ll ydiff = y_cur - y_tar;
      ll kou = __gcd(abs(xdiff), abs(ydiff));
      st.insert(make_pair(xdiff/kou, ydiff/kou));
    }
  }
  cout << st.size() << endl;
}

