#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

map<ll,ll> mp;

ll rec(ll k) {
  if (mp.count(k)) return mp.at(k);
  if (k==0) {
    return 1;
  }

  ll f2 = rec(k/2);
  ll f3 = rec(k/3);
  mp[k] = f2 + f3;
  return f2 + f3;
}

int main() {
  ll N;
  cin >> N;

  cout << rec(N) << endl;
}
