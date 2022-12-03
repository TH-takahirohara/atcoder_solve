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
  ll K;
  cin >> K;

  vector<pair<ll,ll>> vec;
  for (ll i=2; i*i<=K; i++) {
    if (K % i != 0) continue;

    ll kosuu = 0;
    while (K % i == 0) {
      kosuu++;
      K /= i;
    }
    vec.push_back(make_pair(i, kosuu));
  }
  if (K > 1) vec.push_back(make_pair(K, 1));

  // rep(i,0,vec.size()) {
  //   cout << "num: " << vec.at(i).first << " , kosuu: " << vec.at(i).second << endl;
  // }

  ll ans = 0;
  rep(i,0,vec.size()) {
    ll num = vec.at(i).first;
    ll kosuu = vec.at(i).second;

    ll tmp = 0;
    while (kosuu > 0) {
      tmp += num;
      ll tmp2 = tmp;
      while (tmp2 % num == 0) {
        kosuu--;
        tmp2 /= num;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
