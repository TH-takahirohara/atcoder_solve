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

  sort(A.begin(), A.end(), greater<ll>());

  bool flag = true;
  int idx = 0;
  ll ans = 0;
  rep(i,0,N-1) {
    ans += A.at(idx);
    if (flag) {
      flag = false;
      idx++;
    } else {
      flag = true;
    }
  }
  cout << ans << endl;
}
