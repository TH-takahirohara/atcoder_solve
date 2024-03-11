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
  string T;
  cin >> T;
  int N;
  cin >> N;
  vector<vector<string>> S(N);
  rep(ite,0,N) {
    int a;
    cin >> a;
    rep(i,0,a) {
      string s;
      cin >> s;
      S.at(ite).push_back(s);
    }
  }

  int T_sz = T.size();

  vector<vector<int>> dp(T_sz+1, vector<int>(N+1, 1e9));
  dp.at(0).at(0) = 0;

  rep(ite,0,N) {
    if (ite == 0) { // 1群目
      for (string s : S.at(0)) {
        if (s.size() > T_sz) continue;
        if (T.substr(0,s.size()) == s) {
          dp.at(s.size()).at(0) = 1;
        }
      }
    } else { // 2群目以降
      rep(i,0,T_sz+1) { // Tの文字の位置 (idx start 1)
        if (dp.at(i).at(ite-1) > 5e8) continue;

        dp.at(i).at(ite) = min(dp.at(i).at(ite), dp.at(i).at(ite-1));
        for (string s : S.at(ite)) {
          if (i + s.size() > T_sz) continue;
          if (T.substr(i, s.size()) == s) {
            dp.at(i + s.size()).at(ite) = min(dp.at(i + s.size()).at(ite), dp.at(i).at(ite - 1) + 1);
          }
        }
      }
    }
  }

  if (dp.at(T_sz).at(N - 1) > 5e8) cout << -1 << endl;
  else cout << dp.at(T_sz).at(N - 1) << endl;
}
