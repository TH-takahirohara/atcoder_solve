// 一つだけTLEになった解答
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
  int N; ll K;
  cin >> N >> K;
  vector<ll> A(N), rui(N+1);
  rep(i,0,N) cin >> A.at(i);
  
  rep(i,0,N) {
    rui.at(i+1) = rui.at(i) + A.at(i);
  }
  
  map<ll,vector<int>> m;
  
  rep(i,1,N+1) {
    if (!m.count(rui.at(i))) {
      m[rui.at(i)] = {i};
    } else {
      m.at(rui.at(i)).push_back(i);
    }
  }
    
  ll ans = 0LL;
  rep(i,0,N+1) {
    ll tar = K + rui.at(i);
    if (m.count(tar)) {
      vector<int> vec = m.at(tar);
      int num = vec.size() - (upper_bound(vec.begin(), vec.end(), i) - vec.begin());
      ans += (ll)num;
    }
  }
  cout << ans << endl;
}

