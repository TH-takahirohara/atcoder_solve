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
  int R, C, rs, cs;
  cin >> R >> C >> rs >> cs;
  int N; cin >> N;

  map<int,set<int>> mpyoko, mptate;
  rep(i,0,N) {
    int r,c;
    cin >> r >> c;
    if (!mpyoko.count(r)) {
      set<int> tmpst;
      tmpst.insert({0,C+1,c});
      mpyoko[r] = tmpst;
    } else {
      mpyoko[r].insert(c);
    }

    if (!mptate.count(c)) {
      set<int> tmpst;
      tmpst.insert({0,R+1,r});
      mptate[c] = tmpst;
    } else {
      mptate[c].insert(r);
    }
  }

  int Q; cin >> Q;
  rep(iter,0,Q) {
    string d;
    int l;
    cin >> d >> l;
    if (d == "L") {
      if (!mpyoko.count(rs)) {
        cs = max(cs-l, 1);
      } else {
        auto it = mpyoko.at(rs).lower_bound(cs);
        it = (--it);
        cs = max(cs-l, *it + 1);
      }
    } else if (d == "R") {
      if (!mpyoko.count(rs)) {
        cs = min(cs+l, C);
      } else {
        auto it = mpyoko.at(rs).lower_bound(cs);
        cs = min(cs+l, *it-1);
      }
    } else if (d == "U") {
      if (!mptate.count(cs)) {
        rs = max(rs-l, 1);
      } else {
        auto it = mptate.at(cs).lower_bound(rs);
        it = (--it);
        rs = max(rs-l, *it+1);
      }
    } else {
      if (!mptate.count(cs)) {
        rs = min(rs+l, R);
      } else {
        auto it = mptate.at(cs).lower_bound(rs);
        rs = min(rs+l, *it-1);
      }
    }
    cout << rs << " " << cs << endl;
  }
}
