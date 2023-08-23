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
  int R, C;
  cin >> R >> C;
  vector<string> A(R), B(R);
  rep(i,0,R) cin >> A.at(i);
  rep(i,0,R) cin >> B.at(i);

  string ans = "No";
  rep(i,0,R) {
    rep(j,0,C) {
      bool can = true;
      rep(k,0,R) {
        rep(l,0,C) {
          if (A.at(k).at(l) != B.at((i+k) % R).at((j+l) % C)) can = false;
        }
      }
      if (can) ans = "Yes";
    }
  }

  cout << ans << endl;
}
