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
  int N;
  cin >> N;
  vector<int> B(N), C(N);
  vector<ll> num_a(N+1);
  rep(i,0,N) {
    int tmp; cin >> tmp;
    num_a.at(tmp)++;
  }
  rep(i,0,N) cin >> B.at(i);
  rep(i,0,N) cin >> C.at(i);

  ll ans = 0;
  rep(i,0,N) {
    ans += num_a.at(B.at(--C.at(i)));
  }
  cout << ans << endl;
}
