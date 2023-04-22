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
  int N;
  string S;
  cin >> N >> S;

  bool nokusi = true;
  bool nomaru = true;
  rep(i,0,N) {
    if (S.at(i) == '-') nokusi = false;
    if (S.at(i) == 'o') nomaru = false;
  }

  if (nokusi || nomaru) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  int lv = 0;
  int now = 0;
  rep(i,0,N) {
    char c = S.at(i);
    if (c == 'o') {
      now++;
    } else {
      ans = max(ans, now);
      now = 0;
    }
  }
  ans = max(ans, now);

  cout << ans << endl;
}
