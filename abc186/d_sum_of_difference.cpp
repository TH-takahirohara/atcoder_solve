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
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  ll ans = 0LL;
  rep(i,0,N) {
    ans += (N-1-i) * A.at(i) - i * A.at(i);
  }
  cout << ans << endl;
}

