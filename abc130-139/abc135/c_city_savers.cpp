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
  int N;
  cin >> N;
  vector<ll> A(N+1), B(N);
  rep(i,0,N+1) cin >> A.at(i);
  rep(i,0,N) cin >> B.at(i);

  ll ans = 0;
  rep(i,0,N) {
    if (B.at(i) < A.at(i)) {
      ans += B.at(i);
    } else {
      ans += A.at(i);
      ll nokori = B.at(i) - A.at(i);
      ll taosu = min(nokori, A.at(i+1));
      ans += taosu;
      A.at(i+1) -= taosu;
    }
  }

  cout << ans << endl;
}
