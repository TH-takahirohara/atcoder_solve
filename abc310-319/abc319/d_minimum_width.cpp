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
  ll M;
  cin >> N >> M;
  vector<ll> L(N);
  rep(i,0,N) cin >> L.at(i);

  ll ng = 0;
  ll ok = 8e18;
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;
    ll haba = mid;
    ll gyou = 1;
    ll umaru = 0;
    bool can = true;
    rep(i,0,N) {
      if (L.at(i) > haba) {
        can = false;
        break;
      }

      if (i==0) {
        umaru = L.at(i);
      } else if (umaru + L.at(i) + 1 > mid) {
        gyou++;
        umaru = L.at(i);
      } else {
        umaru += (1 + L.at(i));
      }
    }
    if (!can) { // 幅が狭すぎる
      ng = mid;
    } else if (gyou > M) {
      ng = mid;
    } else {
      ok = mid;
    }
  }
  cout << ok << endl;
}
