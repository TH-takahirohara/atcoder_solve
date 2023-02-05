#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll A,B;

double calc(ll n) {
  return (double)B*n + (double)A / (sqrt(1+n));
}

int main() {
  cin >> A >> B;
  ll left = 0;
  ll right = 2e18;
  rep(i,0,10000) {
    ll c1 = (left + left + right) / 3;
    ll c2 = (left + right + right) / 3;
    if (calc(c1) <= calc(c2)) right = c2;
    else left = c1;
  }
  ll ans;
  if (left != right) ans = left + 1;
  else ans = left;
  cout << fixed << setprecision(10) << calc(ans) << endl;
}
