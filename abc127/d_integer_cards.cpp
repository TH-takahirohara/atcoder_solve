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
  int N,M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  sort(A.begin(), A.end());

  vector<pair<ll,ll>> vec(M);
  rep(i,0,M) {
    ll b, c;
    cin >> b >> c;
    vec.at(i) = make_pair(-c,b);
  }
  sort(vec.begin(), vec.end());

  int idx = 0;
  ll ans = 0;
  rep(i,0,M) {
    ll c = -vec.at(i).first;
    ll b = vec.at(i).second;
    int cnt = 0;
    while (cnt < b && idx < N) {
      if (A.at(idx) < c) {
        cnt++;
        idx++;
      } else {
        break;
      }
    }
    ans += c*cnt;
  }
  if (idx < N) {
    for (int i=idx; i<N; i++) ans += A.at(i);
  }
  cout << ans << endl;
}
