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

int R, C;
int ans = 0;
vector<vector<int>> A;
vector<vector<int>> dp;

void rec(int r, int c, set<int> st) {
  if (r == R-1 && c == C-1) {
    ans++;
    return;
  }
  if (r+1 < R) {
    if (!st.count(A.at(r+1).at(c))) {
      set<int> nst = st;
      nst.insert(A.at(r+1).at(c));
      rec(r+1, c, nst);
    }
  }

  if (c+1 < C) {
    if (!st.count(A.at(r).at(c+1))) {
      set<int> nst2 = st;
      nst2.insert(A.at(r).at(c+1));
      rec(r, c+1, nst2);
    }
  }
}

int main() {
  cin >> R >> C;
  A.assign(R, vector<int>(C));
  rep(i,0,R) {
    rep(j,0,C) {
      cin >> A.at(i).at(j);
    }
  }

  set<int> stf;
  stf.insert(A.at(0).at(0));
  rec(0,0,stf);

  cout << ans << endl;
}
