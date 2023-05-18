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
  cin >> N;
  string S;
  cin >> S;
  bool is_in = false;
  string ans = "out";
  rep(i,0,N) {
    char c = S.at(i);
    if (c == '|' && !is_in) {
      is_in = true;
    } else if (c == '|' && is_in) {
      is_in = false;
    } else if (c == '*' && is_in) {
      ans = "in";
    }
  }
  cout << ans << endl;
}
