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
  int T;
  cin >> T;
  rep(i,0,T) {
    ll N;
    cin >> N;
    ll sosuu;
    for (ll i=2; i*i*i <= N; i++) {
      if (N % i != 0) continue;
      sosuu = i;
      break;
    }

    ll kata = N / sosuu;
    if (sqrt(kata) - (double)floor(sqrt(kata)) == 0.0) { // sosuu = qの場合 （kataがq^2の場合）
      cout << (ll)sqrt(kata) << " " << sosuu << endl;
      continue;
    }
    // sosuu = p の場合
    cout << sosuu << " " << N/(sosuu * sosuu) << endl;
  }
}
