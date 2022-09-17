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
  ll n;
  cin >> n;

  ll N = n;
  vector<int> keta;

  int cnt = 0;
  int cnt1 = 0;
  while (cnt < 65) {
    if (N % 2 == 1) {
      keta.push_back(cnt);
      cnt1++;
    }
    N /= 2;
    cnt++;
  }

  vector<ll> kake(61);
  kake.at(0) = 1;
  rep(i,0,60) {
    kake.at(i+1) = kake.at(i) * 2;
  }

  vector<ll> ans;
  for (int i=0; i < (1<<cnt1); i++) {
    ll tmp = 0;
    rep(j,0,cnt1) {
      if (i & (1<<j)) {
        tmp += kake.at(keta.at(j));
      }
    }
    ans.push_back(tmp);
  }

  rep(i,0,ans.size()) cout << ans.at(i) << endl;
}
