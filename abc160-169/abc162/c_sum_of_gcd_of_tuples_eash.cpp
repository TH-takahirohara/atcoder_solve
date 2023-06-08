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
  int K;
  cin >> K;

  int ans = 0;
  rep(a,1,K+1) {
    rep(b,1,K+1) {
      rep(c,1,K+1) {
        ans += __gcd(__gcd(a,b), c);
      }
    }
  }
  cout << ans << endl;
}
