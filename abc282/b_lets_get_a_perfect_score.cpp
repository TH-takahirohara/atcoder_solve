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
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  int ans = 0;
  rep(i,0,N) {
    rep(j,i+1,N) {
      bool can = true;
      rep(k,0,M) {
        if (S.at(i).at(k) == 'x' && S.at(j).at(k) == 'x') can = false;
      }
      if (can) ans++;
    }
  }
  cout << ans << endl;
}
