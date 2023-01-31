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
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  sort(A.begin(), A.end());

  double kake_d = 1.0;
  ull kake = 1;
  bool big = false;
  rep(i,0,N) {
    if (kake_d * A.at(i) > 1e19) {
      big = true;
      break;
    }

    kake *= A.at(i);
    kake_d *= A.at(i);
    if (kake > 1000000000000000000ULL) {
      big = true;
      break;
    }
  }

  if (big) cout << -1 << endl;
  else cout << kake << endl;
}
