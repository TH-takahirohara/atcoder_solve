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
  int R, C;
  cin >> R >> C;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);

  rep(i,0,R) {
    rep(j,0,C) {
      if (S.at(i).at(j) != 's') continue;
      for (int k=-1; k <= 1; k++) {
        for (int l=-1; l <= 1; l++) {
          if (k==0 && l==0) continue;
          int nowr = i;
          int nowc = j;
          vector<pair<int,int>> vec;
          vec.push_back(make_pair(nowr+1, nowc+1));
          string st = "nuke";
          int cnt = 0;
          while (true) {
            nowr += k;
            nowc += l;
            if (nowr < 0 || nowr >= R || nowc < 0 || nowc >= C) break;
            if (st.at(cnt) != S.at(nowr).at(nowc)) break;
            cnt++;
            vec.push_back(make_pair(nowr+1, nowc+1));
            if (cnt == 4) break;
          }
          if (vec.size() == 5) {
            rep(ite,0,vec.size()) {
              cout << vec.at(ite).first << " " << vec.at(ite).second << endl;
            }
            return 0;
          }
        }
      }
    }
  }
}
