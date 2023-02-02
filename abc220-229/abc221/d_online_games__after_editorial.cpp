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
  
  vector<ll> ans(N+1);
  vector<pair<ll,ll>> vec;
  rep(i,0,N) {
    ll a,b;
    cin >> a >> b;
    vec.emplace_back(a, 1);
    vec.emplace_back(a+b, -1);
  }
  
  sort(vec.begin(), vec.end());
  
  ll cnt = 0;
  rep(i,0,2*N-1) {
    cnt += vec.at(i).second;
    ans.at(cnt) += vec.at(i+1).first - vec.at(i).first;
  }
  
  rep(i,1,N+1) cout << ans.at(i) << " ";
}

