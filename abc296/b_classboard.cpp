#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  vector<string> S(8);
  rep(i,0,8) cin >> S.at(i);

  int r = 0;
  int c = 0;
  rep(i,0,8) {
    rep(j,0,8) {
      if (S.at(i).at(j) == '*') {
        r = i;
        c = j;
      }
    }
  }

  int ra = 8 - r;
  char ca = char('a' + c);

  cout << ca << ra << endl;
}
