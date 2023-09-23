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
  int N, M;
  ll P;
  cin >> N >> M >> P;
  vector<ll> A(N), B(M);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,M) cin >> B.at(i);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  vector<ll> rui(M+1);
  rep(i,0,M) rui.at(i+1) = rui.at(i) + B.at(i);

  ll ans = 0;
  rep(i,0,N) {
    ll tar = P - A.at(i);
    int idx = lower_bound(B.begin(), B.end(), tar) - B.begin();
    ans += A.at(i) * idx + rui.at(idx) + P * (M-idx);
  }
  cout << ans << endl;
}
