// ほぼ解説を見て解いた。解説の内容も正確には理解できなかった。
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 1000000007LL;

int main() {
  ll N,M;
  cin >> N >> M;
  
  vector<vector<ll>> vec(N);
  rep(i,0,M) {
    ll a,b;
    cin >> a >> b;
    a--;b--;
    vec.at(a).push_back(b);
    vec.at(b).push_back(a);
  }
    
  vector<ll> cnts(N, 0), dist(N, 0);
  vector<bool> seen(N, false);
  
  queue<ll> que;
  cnts.at(0) = 1;
  seen.at(0) = true;
  que.push(0);
  
  while (!que.empty()) {
    ll v = que.front();
    que.pop();
        
    for (auto nv : vec.at(v)) {
      if (!seen.at(nv)) {
        seen.at(nv) = true;
        dist.at(nv) = dist.at(v) + 1;
        cnts.at(nv) = cnts.at(v);
        que.push(nv);
      } else if (seen.at(nv) && dist.at(nv) == dist.at(v) + 1) {
        cnts.at(nv) += cnts.at(v);
        cnts.at(nv) %= MOD;
      }
    }
  }
  
  cout << cnts.at(N-1) << endl;
}

