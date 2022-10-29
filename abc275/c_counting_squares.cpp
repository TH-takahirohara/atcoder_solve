#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<string> S(9);
set<vector<pair<int,int>>> st;

void add_pair(pair<int,int> p1, pair<int,int> p2, int rdiff, int cdiff) {
  int nr1 = p1.first + rdiff;
  int nc1 = p1.second + cdiff;
  int nr2 = p2.first + rdiff;
  int nc2 = p2.second + cdiff;
  if (nr1 >= 0 && nr1 < 9 && nr2 >= 0 && nr2 < 9 && nc1 >= 0 && nc1 < 9 && nc2 >= 0 && nc2 < 9) {
    if (S.at(nr1).at(nc1) == '#' && S.at(nr2).at(nc2) == '#') {
      vector<pair<int,int>> v = {make_pair(p1.first,p1.second), make_pair(p2.first,p2.second), make_pair(nr1,nc1), make_pair(nr2,nc2)};
      sort(v.begin(), v.end());
      st.insert(v);
    }
  }
}

int main() {
  rep(i,0,9) cin >> S.at(i);

  rep(r1,0,9) {
    rep(c1,0,9) {
      if (S.at(r1).at(c1) == '.') continue;

      rep(r2,0,9) {
        rep(c2,0,9) {
          if ((r1 == r2) && (c1 == c2)) continue;
          if (S.at(r2).at(c2) == '.') continue;
          int rdiff = r1 - r2;
          int cdiff = c1 - c2;
          add_pair(make_pair(r1,c1), make_pair(r2,c2), cdiff, -rdiff);
          add_pair(make_pair(r1,c1), make_pair(r2,c2), -cdiff, rdiff);
        }
      }
    }
  }

  cout << st.size() << endl;
}
