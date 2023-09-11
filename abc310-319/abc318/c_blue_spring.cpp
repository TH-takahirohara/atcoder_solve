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
  int N, D, P;
  cin >> N >> D >> P;
  vector<ll> F(N);
  rep(i,0,N) cin >> F.at(i);

  sort(F.begin(), F.end());
  vector<ll> rui(N+1);
  rep(i,0,N) rui.at(i+1) = rui.at(i) + F.at(i);

  ll ans = 8e18;
  int num_pas = 0;
  ll shuuyuu = 0;
  while (true) {
    if (num_pas > N) break;
    ll tmp = rui.at(N - num_pas) + shuuyuu;
    ans = min(ans, tmp);
    num_pas += D;
    shuuyuu += P;
  }
  ans = min(ans, (((ll)N + (ll)D) / (ll)D * (ll)P));
  cout << ans << endl;
}
