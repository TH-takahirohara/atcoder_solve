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
  int N;
  cin >> N;
  string T;
  cin >> T;
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  string Tinv = T;
  reverse(Tinv.begin(), Tinv.end());

  vector<int> mae(N);
  vector<int> ato(N);

  rep(ite,0,N) {
    string s = S.at(ite);
    int idx = 0;
    rep(i,0,s.size()) {
      if (idx > (T.size() - 1)) break;
      if (s.at(i) == T.at(idx)) {
        idx++;
      }
    }
    mae.at(ite) = idx;
  }

  rep(ite,0,N) {
    string s = S.at(ite);
    string sinv = s;
    reverse(sinv.begin(), sinv.end());

    int idx = 0;
    rep(i,0,sinv.size()) {
      if (idx > (T.size() - 1)) break;
      if (sinv.at(i) == Tinv.at(idx)) {
        idx++;
      }
    }
    ato.at(ite) = idx;
  }

  sort(ato.begin(), ato.end());

  // rep(i,0,N) {
  //   cout << mae.at(i) << " ";
  // }
  // cout << endl;
  // rep(i,0,N) {
  //   cout << ato.at(i) << " ";
  // }
  // cout << endl;

  ll ans = 0;
  rep(ite,0,N) {
    int num = mae.at(ite);
    int tar = T.size() - num;
    // cout << "num: " << num << " tar: " << tar << endl;
    ll cnt = ato.size() - (lower_bound(ato.begin(), ato.end(), tar) - ato.begin());
    // cout << "ite: " << ite << " " << cnt << endl;
    ans += cnt;
  }
  cout << ans << endl;
}
