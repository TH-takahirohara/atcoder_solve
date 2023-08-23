#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> C(N), D(M);
  rep(i,0,N) cin >> C.at(i);
  rep(i,0,M) cin >> D.at(i);
  int P0;
  vector<int> P(M);
  cin >> P0;
  rep(i,0,M) cin >> P.at(i);

  map<string,int> mp;
  rep(i,0,M) {
    mp[D.at(i)] = P.at(i);
  }

  int ans = 0;
  rep(i,0,N) {
    if (mp.count(C.at(i))) {
      ans += mp.at(C.at(i));
    } else {
      ans += P0;
    }
  }
  cout << ans << endl;
}
