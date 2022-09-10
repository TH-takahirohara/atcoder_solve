#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll score(vector<int> &vec) {
  ll res = 0;
  rep(i,0,10) {
    ll res2 = 1;
    rep(j,0,vec.at(i)) res2 *= 10;
    res += res2 * i;
  }
  return res;
}

int main() {
  ll K;
  string S,T;
  cin >> K >> S >> T;

  vector<int> cards(10, K);
  rep(i,0,4) {
    cards.at(S.at(i) - '0')--;
    cards.at(T.at(i) - '0')--;
  }

  ll pat = (9*K-8)*(9*K-9);
  // cout << pat << endl;
  double ans = 0.0;
  rep(i,1,10) {
    rep(j,1,10) {
      vector<int> nc = cards;
      vector<int> taka(10);
      vector<int> aoki(10);
      rep(k,0,4) {
        taka.at(S.at(k) - '0')++;
        aoki.at(T.at(k) - '0')++;
      }
      taka.at(i)++;
      aoki.at(j)++;

      if (score(taka) <= score(aoki)) continue;
      // cout << "ij: " << i << j << endl;
      ll cnt = max(nc.at(i), 0);
      nc.at(i)--;
      cnt *= max(nc.at(j), 0);
      ans += (double)cnt / pat;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}
