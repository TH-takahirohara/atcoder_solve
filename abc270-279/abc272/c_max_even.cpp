#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N; cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  int num_even = 0, num_odd = 0;
  rep(i,0,N) {
    if (A.at(i) % 2 == 0) num_even++;
    else num_odd++;
  }

  if (!(num_even >= 2 || num_odd >= 2)) {
    cout << -1 << endl;
    return 0;
  }

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  ll ans = 0;
  if (num_even >= 2) {
    ll tmp = 0;
    int cnt = 0;
    rep(i,0,N) {
      if (cnt == 2) break;
      if (A.at(i) % 2 == 0) {
        tmp += A.at(i);
        cnt++;
      }
    }
    ans = tmp;
  }

  if (num_odd >= 2) {
    ll tmp = 0;
    int cnt = 0;
    rep(i,0,N) {
      if (cnt == 2) break;
      if (A.at(i) % 2 == 1) {
        tmp += A.at(i);
        cnt++;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
