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
  ll B;
  cin >> B;

  for (ll i=1; i<=15; i++) {
    // ll j = i;
    ll res = 1;
    for (int j=1; j<=i; j++) {
      res *= i;
    }
    if (B == res) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
