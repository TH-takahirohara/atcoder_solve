#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 998244353;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> kake(20);
  rep(i,0,20) {
    ll n = 1;
    rep(j,0,i) {
      n *= 10;
    }
    kake.at(i) = n;
  }

  ll ans = 0;
  ll sum = A.at(N-1);
  map<ll,ll> mp;
  string str = to_string(A.at(N-1));
  mp[str.size()]++;
  for (int i=N-2; i >= 0; i--) {
    ll num = A.at(i);

    for (auto p : mp) {
      ll mojityou = p.first;
      ll value = p.second;

      ll tmp = (kake.at(mojityou) % MOD) * num % MOD * value % MOD;
      ans += tmp;
      ans %= MOD;
    }
    ans += sum;
    ans %= MOD;
    sum += num;
    sum %= MOD;

    string strin = to_string(num);
    mp[strin.size()]++;
  }
  cout << ans % MOD << endl;
}
