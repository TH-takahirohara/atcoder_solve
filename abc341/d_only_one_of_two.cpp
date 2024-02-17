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
  ull N, M, K;
  cin >> N >> M >> K;

  ull kou = N / __gcd(N, M) * M;

  ull ng = 0;
  ull ok = 2e18;
  while (ok - ng > 1) {
    ull mid = (ng + ok) / 2;
    ull kosuu = (mid / N) + (mid / M) - 2 * (mid / kou);
    if (kosuu < K) {
      ng = mid;
    } else if (kosuu > K) {
      ok = mid;
    } else { // kosuu == K
      if (mid % N == 0 && mid % M != 0) {
        cout << mid << endl;
        return 0;
      } else if (mid % N != 0 && mid % M == 0) {
        cout << mid << endl;
        return 0;
      } else {
        ok = mid;
      }
    }
  }
  cout << ok << endl;
}
