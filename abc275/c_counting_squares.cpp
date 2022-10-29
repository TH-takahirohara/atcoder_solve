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
  vector<string> S(9);
  rep(i,0,9) cin >> S.at(i);

  int ans = 0;
  set<vector<pair<int,int>>> st;
  rep(r1,0,9) {
    rep(c1,0,9) {
      if (S.at(r1).at(c1) == '.') continue;

      rep(r2,0,9) {
        rep(c2,0,9) {
          if ((r1 == r2) && (c1 == c2)) continue;
          if (S.at(r2).at(c2) == '.') continue;
          // cout << r1 << " " << c1 << " : " << r2 << " " << c2 << endl;
          int rdiff = r1 - r2;
          int cdiff = c1 - c2;
          int nr1 = r1 + cdiff;
          int nc1 = c1 - rdiff;
          int nr2 = r2 + cdiff;
          int nc2 = c2 - rdiff;
          if (nr1 >= 0 && nr1 < 9 && nr2 >= 0 && nr2 < 9 && nc1 >= 0 && nc1 < 9 && nc2 >= 0 && nc2 < 9) {
            if (S.at(nr1).at(nc1) == '#' && S.at(nr2).at(nc2) == '#') {
              vector<pair<int,int>> v1 = {make_pair(r1,c1), make_pair(r2,c2), make_pair(nr1,nc1), make_pair(nr2,nc2)};
              sort(v1.begin(), v1.end());
              
              st.insert(v1);
            }
          }

          int nr3 = r1 - cdiff;
          int nc3 = c1 + rdiff;
          int nr4 = r2 - cdiff;
          int nc4 = c2 + rdiff;
          if (nr3 >= 0 && nr3 < 9 && nr4 >= 0 && nr4 < 9 && nc3 >= 0 && nc3 < 9 && nc4 >= 0 && nc4 < 9) {
            if (S.at(nr3).at(nc3) == '#' && S.at(nr4).at(nc4) == '#') {
              vector<pair<int,int>> v2 = {make_pair(r1,c1), make_pair(r2,c2), make_pair(nr3,nc3), make_pair(nr4,nc4)};
            sort(v2.begin(), v2.end());
            st.insert(v2);
            }
            
          }
        }
      }
    }
  }

  // for (auto v : st) {
  //   rep(i,0,4) {
  //     cout << v.at(i).first << " " << v.at(i).second << " : ";
  //   }
  //   cout << endl;
  // }

  cout << st.size() << endl;
}
