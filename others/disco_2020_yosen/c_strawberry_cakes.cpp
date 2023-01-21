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
  int R, C, K;
  cin >> R >> C >> K;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);

  vector<vector<int>> ans(R, vector<int>(C));
  int num = 1;
  rep(i,0,R) {
    rep(j,0,C) {
      if (S.at(i).at(j) == '#') {
        ans.at(i).at(j) = num;
        num++;
      }
    }
  }

  rep(i,0,R) {
    rep(j,0,C) {
      if (ans.at(i).at(j) == 0) continue;
      int n = ans.at(i).at(j);
      int i1 = i; int j1 = j;
      while (true) {
        j1--;
        if (j1 < 0 || ans.at(i1).at(j1) > 0) {
          break;
        } else {
          ans.at(i1).at(j1) = n;
        }
      }
      i1 = i; j1 = j;
      while (true) {
        j1++;
        if (j1 >= C || ans.at(i1).at(j1) > 0) {
          break;
        } else {
          ans.at(i1).at(j1) = n;
        }
      }
    }
  }

  rep(i,0,R) {
    rep(j,0,C) {
      if (ans.at(i).at(j) == 0) continue;
      int n = ans.at(i).at(j);
      int i1 = i; int j1 = j;
      while (true) {
        i1--;
        if (i1 < 0 || ans.at(i1).at(j1) > 0) {
          break;
        } else {
          ans.at(i1).at(j1) = n;
        }
      }
      i1 = i; j1 = j;
      while (true) {
        i1++;
        if (i1 >= R || ans.at(i1).at(j1) > 0) {
          break;
        } else {
          ans.at(i1).at(j1) = n;
        }
      }
    }
  }

  rep(i,0,R) {
    rep(j,0,C) {
      cout << ans.at(i).at(j) << " ";
    }
    cout << endl;
  }
}
