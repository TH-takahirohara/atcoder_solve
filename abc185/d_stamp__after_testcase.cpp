// テストケースを見た後にAC
// ほぼあっていたが、M==0のケースでNを出力するという誤り(正しくは1)に気づかなかった。
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll N,M;
  cin >> N >> M;
  
  if (M==0) {
    cout << 1 << endl;
    return 0;
  } else if (M==N) {
    cout << 0 << endl;
    return 0;
  }
    
  vector<ll> A(M), W;
  rep(i,0,M) {
    ll tmp; cin >> tmp;
    tmp--;
    A.at(i) = tmp;
  }
  
  sort(A.begin(), A.end());
  
  rep(i,0,M) {
    if (i==0) {
      if (A.at(i) > 0) W.push_back(A.at(i));
    } else {
      if (A.at(i) - A.at(i-1) > 1) W.push_back(A.at(i) - A.at(i-1) - 1);
    }
  }
  if (N - A.at(M-1) > 1) W.push_back(N - A.at(M-1) - 1);
    
  ll now = 10000000000LL;
  rep(i,0,W.size()) {
    now = min(now, W.at(i));
  }
  
  ll ans = 0;
  rep(i,0,W.size()) {
    if (W.at(i) % now == 0) ans += W.at(i) / now;
    else ans += W.at(i) / now + 1;
  }
  cout << ans << endl;
}

