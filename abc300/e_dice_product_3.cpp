#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)
using mint = modint998244353;

ll N;
map<ll,mint> mp;

mint rec(ll n) {
  if (mp.count(n)) return mp.at(n);
  if (n == N) return 1;
  if (n > N) return 0;
  mint r2 = rec(2*n), r3 = rec(3*n), r4 = rec(4*n), r5 = rec(5*n), r6 = rec(6*n);
  mp[2*n] = r2;
  mp[3*n] = r3;
  mp[4*n] = r4;
  mp[5*n] = r5;
  mp[6*n] = r6;
  return (r2 + r3 + r4 + r5 + r6) / 5;
}

int main() {
  cin >> N;

  cout << rec(1).val() << endl;
}
