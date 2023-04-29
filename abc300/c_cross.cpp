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

vector<int> dr = {1, 1, -1, -1};
vector<int> dc = {1, -1, 1, -1};

int main() {
  int R, H;
  cin >> R >> H;
  int N = min(R,H);
  vector<int> vec(N+1);

  vector<string> C(R);
  rep(i,0,R) cin >> C.at(i);

  rep(i,0,R) {
    rep(j,0,H) {
      if (i-1 < 0 || i+1 >= R || j-1 < 0 || j+1 >= H) continue;
      if (C.at(i).at(j) == '#' && C.at(i+1).at(j+1) == '#' && C.at(i+1).at(j-1) == '#' && C.at(i-1).at(j+1) == '#' && C.at(i-1).at(j-1) == '#') {
        int n = 1000;
        rep(k,0,4) {
          int tmp = 0;
          int in = i + dr.at(k), jn = j + dc.at(k);
          while (true) {
            if (in < 0 || in >= R || jn < 0 || jn >= H) break;
            if (C.at(in).at(jn) == '.') break;
            in += dr.at(k);
            jn += dc.at(k);
            tmp++;
          }
          n = min(n, tmp);
        }
        vec.at(n)++;
      }
    }
  }

  rep(i,1,N+1) cout << vec.at(i) << " ";
  cout << endl;
}
