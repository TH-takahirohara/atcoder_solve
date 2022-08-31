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
  ll N,X; cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  cin >> X;

  ll sum_a = 0;
  rep(i,0,N) sum_a += A.at(i);

  ll ans = 0;
  ll loop = X / sum_a;
  ans += loop * N;
  X -= sum_a * loop;
  rep(i,0,N) {
    ans++;
    X -= A.at(i);
    if (X < 0) break;
  }
  cout << ans << endl;
}
