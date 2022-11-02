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

  int ans = 0;
  rep(i,1,N+1) {
    rep(j,1,N+1) {
      int wh = K - i - j;
      if (wh >= 1 && wh <= N) ans++;
    }
  }

  cout << ans << endl;
}
