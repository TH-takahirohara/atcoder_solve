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
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  ll sum = 0;
  ll ans = 0;
  for (int i=N-1; i>=0; i--) {
    ans += (N-1)*A.at(i)*A.at(i) - 2*A.at(i)*sum;
    sum += A.at(i);
  }
  cout << ans << endl;
}
