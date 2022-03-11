// 下記の半分前列挙の記事を見てから取り組んだ。
// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#5-%E3%81%AF%E3%82%84%E3%81%84%E6%8E%A2%E7%B4%A2%E6%B3%95%E5%8D%8A%E5%88%86%E5%85%A8%E5%88%97%E6%8C%99
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> P(N+1);
  P.at(0) = 0;
  rep(i,0,N) cin >> P.at(i+1);
  
  vector<ll> W;
  rep(i,0,N+1) {
    rep(j,0,N+1) {
      W.push_back(P.at(i) + P.at(j));
    }
  }
  
  sort(W.begin(), W.end());
  
  ll ans = 0LL;
  for (auto v : W) {
    ll tar = M - v;
    ll idx = upper_bound(W.begin(), W.end(), tar) - W.begin() - 1;
    if (idx == -1) idx = 0;
    if (v + W.at(idx) > M) continue;
    ans = max(ans, v + W.at(idx));
  }
  
  cout << ans << endl;
}
