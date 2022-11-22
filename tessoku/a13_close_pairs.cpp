// しゃくとり法
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
  int N, K;
  cin >> N >> K;
  vector<int> A(N), R(N);
  rep(i,0,N) cin >> A.at(i);

  rep(i,0,N) {
    int idx;
    if (i == 0) idx = 0;
    else idx = R.at(i-1);

    int tmp = idx;
    rep(j,idx+1,N) {
      if (A.at(j) - A.at(i) > K) {
        break;
      }
      tmp = j;
    }
    R.at(i) = tmp;
  }

  ll ans = 0;
  rep(i,0,N) {
    ans += (ll)R.at(i) - i;
  }
  cout << ans << endl;
}
